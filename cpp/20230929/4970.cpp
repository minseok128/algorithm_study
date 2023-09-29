#include <iostream>
#include <vector>
using namespace std;

int g_round_p, g_round_q, g_round_r;

typedef enum {
	CONSTANT,
	VARIABLE,
	NOT,
	AND,
	OR,
	PAR_OPEN,
	PAR_CLOSE,
} TokenType;

typedef struct s_token {
	TokenType type;
	int value;
	s_token(TokenType t, int v = 0) : type(t), value(v) {};
} t_token;
using Tokensit = vector<t_token>::iterator;

struct s_node {
	virtual int eval(void) = 0;
};

struct s_const : public s_node {
	int value;

	s_const(int v) : value(v) {};
	virtual int eval()
	{
		return (value);
	}
};

struct s_var : public s_node {
	int num;

	s_var(int n) : num(n) {};
	virtual int eval()
	{
		if (num == 0)
			return (g_round_p);
		if (num == 1)
			return (g_round_q);
		return (g_round_r);
	}
};

struct s_not : public s_node {
	s_node *child;

	s_not(s_node *c) : child(c) {};
	virtual int eval() {
		int tmp = child->eval();
		if (tmp == 0)
			return (2);
		if (tmp == 1)
			return (1);
		return (0);
	}
};

struct s_and : public s_node {
	s_node *left, *right;

	s_and(s_node *l, s_node *r) : left(l), right(r) {};
	virtual int eval()
	{
		int tmp1 = left->eval(), tmp2 = right->eval();
		if (tmp1 == 2 && tmp2 == 2)
			return (2);
		if (tmp1 > 0 && tmp2 > 0)
			return (1);
		return (0);
	}
};

struct s_or : public s_node {
	s_node *left, *right;

	s_or(s_node *l, s_node *r) : left(l), right(r) {};
	virtual int eval()
	{
		int tmp1 = left->eval(), tmp2 = right->eval();
		if (tmp1 == 2 || tmp2 == 2)
			return (2);
		if (tmp1 == 1 || tmp2 == 1)
			return (1);
		return (0);
	}
};

vector<t_token> tokenize(string s)
{
	vector<t_token> res;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			res.emplace_back(t_token(PAR_OPEN));
		else if (s[i] == ')')
			res.emplace_back(t_token(PAR_CLOSE));
		else if (s[i] == '-')
			res.emplace_back(t_token(NOT));
		else if (s[i] == '*')
			res.emplace_back(t_token(AND));
		else if (s[i] == '+')
			res.emplace_back(t_token(OR));
		else if (s[i] == '0' || s[i] == '1' || s[i] == '2')
			res.emplace_back(t_token(CONSTANT, s[i] - '0'));
		else if (s[i] == 'P' || s[i] == 'Q' || s[i] == 'R')
			res.emplace_back(t_token(VARIABLE, s[i] - 'P'));
	}
	return (res);
}

int parse_formual(Tokensit tk_begin, Tokensit tk_end, s_node **ast)
{
	int token_cnt = 0;
	s_node *left, *right;

	if (tk_begin->type == PAR_OPEN)
	{
		token_cnt += parse_formual(tk_begin + 1, tk_end, &left) + 1;
		if ((tk_begin + token_cnt)->type == AND)
		{
			token_cnt += parse_formual(tk_begin + token_cnt + 1, tk_end, &right) + 2;
			*ast = new s_and(left, right);
		}
		else if ((tk_begin + token_cnt)->type == OR)
		{
			token_cnt += parse_formual(tk_begin + token_cnt + 1, tk_end, &right) + 2;
			*ast = new s_or(left, right);
		}
	}
	else if (tk_begin->type == NOT)
	{
		token_cnt += parse_formual(tk_begin + 1, tk_end, &left) + 1;
		*ast = new s_not(left);
	}
	else if (tk_begin->type == VARIABLE)
	{
		token_cnt++;
		*ast = new s_var(tk_begin->value);
	}
	else if (tk_begin->type == CONSTANT)
	{
		token_cnt++;
		*ast = new s_const(tk_begin->value);
	}
	return (token_cnt);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		string s;
		cin >> s;
		if (s == ".")
			break ;
		
		vector<t_token> tokens = tokenize(s);
		s_node *ast;
		parse_formual(tokens.begin(), tokens.end(), &ast);
		int res = 0;
		for (g_round_p = 0; g_round_p < 3; g_round_p++)
			for (g_round_q = 0; g_round_q < 3; g_round_q++)
				for (g_round_r = 0; g_round_r < 3; g_round_r++)
					if (ast->eval() == 2)
						res++;
		cout << res << '\n';
	}
}