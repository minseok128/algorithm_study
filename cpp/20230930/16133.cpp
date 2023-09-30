#include <iostream>
#include <vector>
#define int64 int64_t
using namespace std;

typedef enum
{
	NUM,
	PLUS,
	MINUS,
	MUL,
	DIV,
	POWER,
	SQRT,
	PAR_OPEN,
	PAR_CLOSE,
	EQUAL
} e_tokentype;

typedef struct s_token
{
	e_tokentype type;
	int64 value;
	s_token(e_tokentype t, int64 v = 0) : type(t), value(v){};
} t_token;
using t_it = vector<t_token>::iterator;

struct s_node
{
	virtual int64 eval(void) = 0;
};

struct s_num : public s_node
{
	int64 value;

	s_num(int64 v) : value(v){};
	virtual int64 eval(void)
	{
		return (value);
	}
};

struct s_add : public s_node
{
	s_node *left, *right;

	s_add(s_node *l, s_node *r) : left(l), right(r){};
	virtual int64 eval(void)
	{
		return (left->eval() + right->eval());
	}
};

struct s_sub : public s_node
{
	s_node *left, *right;

	s_sub(s_node *l, s_node *r) : left(l), right(r){};
	virtual int64 eval(void)
	{
		return (left->eval() - right->eval());
	}
};

struct s_mul : public s_node
{
	s_node *left, *right;

	s_mul(s_node *l, s_node *r) : left(l), right(r){};
	virtual int64 eval(void)
	{
		return (left->eval() * right->eval());
	}
};

struct s_div : public s_node
{
	s_node *left, *right;

	s_div(s_node *l, s_node *r) : left(l), right(r){};
	virtual int64 eval(void)
	{
		return (left->eval() / right->eval());
	}
};

struct s_pow : public s_node
{
	s_node *left, *right;

	s_pow(s_node *l, s_node *r) : left(l), right(r){};
	virtual int64 eval(void)
	{
		int64 res = 1, lv = left->eval(), rv = right->eval();
		while (rv)
		{
			if (rv & 1)
				res *= lv;
			lv *= lv;
			rv /= 2;
		}
		return (res);
	}
};

struct s_sqrt : public s_node
{
	s_node *child;

	s_sqrt(s_node *c) : child(c){};
	virtual int64 eval(void)
	{
		int64 cv = child->eval();
		if (cv <= 0)
			return (0);
		int64 lo = 1, hi = cv + 1;
		while (lo + 1 < hi)
		{
			int64 mid = lo + hi >> 1;
			if (cv / mid >= mid)
				lo = mid;
			else
				hi = mid;
		}
		return (lo);
	}
};

vector<t_token> tokenize(string s)
{
	vector<t_token> res;

	for (int i = 0; s[i] != '='; i++)
	{
		if (s[i] == '+')
			res.emplace_back(t_token(PLUS));
		else if (s[i] == '-')
			res.emplace_back(t_token(MINUS));
		else if (s[i] == '*')
			res.emplace_back(t_token(MUL));
		else if (s[i] == '/')
			res.emplace_back(t_token(DIV));
		else if (s[i] == '^')
			res.emplace_back(t_token(POWER));
		else if (s[i] == '#')
			res.emplace_back(t_token(SQRT));
		else if (s[i] == '(')
			res.emplace_back(t_token(PAR_OPEN));
		else if (s[i] == ')')
			res.emplace_back(t_token(PAR_CLOSE));
		else if (isdigit(s[i]))
		{
			int j = 1;
			while (isdigit(s[i + j]) && i + j < s.size())
				j++;
			res.emplace_back(t_token(NUM, stoll(string(&s[i], j))));
			i += j - 1;
		}
	}
	return (res);
}

int parse_expr(t_it t_begin, t_it t_end, s_node **ast);

int parse_root(t_it t_begin, t_it t_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left;

	if (t_begin->type == PAR_OPEN)
	{
		token_cnt++;
		token_cnt += parse_expr(t_begin + token_cnt, t_end, &left) + 1;
	}
	else
	{
		token_cnt++;
		left = new s_num(t_begin->value);
	}
	// cout << "root:" << token_cnt << '\n';
	*ast = left;
	return (token_cnt);
}

int parse_power(t_it t_begin, t_it t_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left;

	if (t_begin->type == SQRT)
	{
		token_cnt++;
		token_cnt += parse_power(t_begin + token_cnt, t_end, &left);
		left = new s_sqrt(left);
	}
	else
		token_cnt += parse_root(t_begin, t_end, &left);
	// cout << "power:" << token_cnt << '\n';
	*ast = left;
	return (token_cnt);
}

int parse_factor(t_it t_begin, t_it t_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left, *right;

	token_cnt += parse_power(t_begin, t_end, &left);
	if (t_begin + token_cnt != t_end)
	{
		if ((t_begin + token_cnt)->type == POWER)
		{
			token_cnt++;
			token_cnt += parse_factor(t_begin + token_cnt, t_end, &right);
			left = new s_pow(left, right);
		}
	}
	// cout << "factor:" << token_cnt << '\n';
	*ast = left;
	return (token_cnt);
}

int parse_term(t_it t_begin, t_it t_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left, *right;

	token_cnt += parse_factor(t_begin, t_end, &left);
	while (t_begin + token_cnt != t_end && ((t_begin + token_cnt)->type == MUL) || (t_begin + token_cnt)->type == DIV)
	{
		int tmp_tc = token_cnt;
		token_cnt++;
		token_cnt += parse_factor(t_begin + token_cnt, t_end, &right);
		if ((t_begin + tmp_tc)->type == MUL)
			left = new s_mul(left, right);
		else if ((t_begin + tmp_tc)->type == DIV)
			left = new s_div(left, right);
	}
	// cout << "term:" << token_cnt << '\n';
	*ast = left;
	return (token_cnt);
}

int parse_expr(t_it t_begin, t_it t_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left, *right;

	token_cnt += parse_term(t_begin, t_end, &left);
	while (t_begin + token_cnt != t_end && ((t_begin + token_cnt)->type == PLUS) || (t_begin + token_cnt)->type == MINUS)
	{
		int tmp_tc = token_cnt;
		token_cnt++;
		token_cnt += parse_term(t_begin + token_cnt, t_end, &right);
		if ((t_begin + tmp_tc)->type == PLUS)
			left = new s_add(left, right);
		else if ((t_begin + tmp_tc)->type == MINUS)
			left = new s_sub(left, right);
	}
	// cout << "expr:" << token_cnt << '\n';
	*ast = left;
	return (token_cnt);
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string s;
	cin >> s;
	vector<t_token> tokens = tokenize(s);
	// for (int i = 0; i < tokens.size(); i++)
	// {
	// 	if (tokens[i].type == NUM)
	// 		cout << "n:" << tokens[i].value << ' ';
	// 	else
	// 		cout << tokens[i].type << ' ';
	// }
	s_node *ast;
	parse_expr(tokens.begin(), tokens.end(), &ast);
	cout << ast->eval() << '\n';
}