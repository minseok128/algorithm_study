#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using namespace std;

typedef enum {
	BOOLEAN = 0,
	VARIABLE = 1,
	EQUAL = 2,
	QUESTION = 3,
	COLON = 4,
} TokenType;

struct Token {
	TokenType type;
	int value;
	Token(TokenType t, int v = 0) : type(t), value(v) {};
};
using Tokensit = vector<Token>::iterator;

int g_case_num;
char check[67'108'864], use[26];

struct Node {
	virtual int	eval(void) = 0;
};

struct S_Boolean : public Node {
	int value;

	S_Boolean(int v) : value(v) {};
	virtual int	eval(void)
	{
		return (value);
	}
};

struct S_Var : public Node {
	int	num;
	
	S_Var(int n) : num(n) {};
	virtual int	eval(void)
	{
		use[num] = 1;
		// cout << g_case_num  << ":" << (g_case_num & (1 << this->num) ? 1 : 0) << "\n";
		return (g_case_num & (1 << this->num) ? 1 : 0);
	}
};

struct S_Ternary : public Node {
	Node *left, *mid, *right;

	S_Ternary(Node *l, Node *m, Node *r) : left(l), mid(m), right(r) {};
	virtual int eval(void)
	{
		// cout << this->left->eval() << "==" << this->right->eval() << "\n";
		if (this->left->eval())
			return (this->mid->eval());
		else
			return (this->right->eval());
	}
};

struct S_Condition : public Node {
	Node *left, *right;

	S_Condition(Node *l, Node *r) : left(l), right(r) {};
	virtual int eval(void)
	{
		if (this->left->eval() == this->right->eval())
			return (1);
		else
			return (0);
	}
};

vector<Token> tokenize(string s)
{
	vector<Token> res;

	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '0' || s[i] == '1')
			res.emplace_back(Token(BOOLEAN, s[i] == '0' ? 0 : 1));
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			res.emplace_back(Token(VARIABLE, s[i] - 'a'));
			use[s[i] - 'a'] = 1;
		}
		else if (s[i] == '?')
			res.emplace_back(Token(QUESTION));
		else if (s[i] == ':')
			res.emplace_back(Token(COLON));
		else
		{
			res.emplace_back(Token(EQUAL));
			i++;
		}
	}
	return (res);
}

int p_condition(Tokensit it_bigin, Tokensit it_end, Node **ast)
{
	Node *left, *right;

	if (it_bigin->type == BOOLEAN)
		left = new S_Boolean(it_bigin->value);
	else if (it_bigin->type == VARIABLE)
		left = new S_Var(it_bigin->value);
	it_bigin += 2;
	if (it_bigin->type == BOOLEAN)
		right = new S_Boolean(it_bigin->value);
	else if (it_bigin->type == VARIABLE)
		right = new S_Var(it_bigin->value);
	*ast = new S_Condition(left, right);
	return (3);
}

int p_exoression(Tokensit it_bigin, Tokensit it_end, Node **ast)
{
	int token_cnt = 0;
	Node *left, *mid, *right;

	if (it_bigin + 1 != it_end && (it_bigin + 1)->type == EQUAL)
	{
		token_cnt += p_condition(it_bigin, it_end, &left) + 1;
		token_cnt += p_exoression(it_bigin + token_cnt, it_end, &mid) + 1;
		token_cnt += p_exoression(it_bigin + token_cnt, it_end, &right);
		*ast = new S_Ternary(left, mid, right);
	}
	else
	{
		if (it_bigin->type == BOOLEAN)
			*ast = new S_Boolean(it_bigin->value);
		else if (it_bigin->type == VARIABLE)
			*ast = new S_Var(it_bigin->value);
		token_cnt++;
	}
	return (token_cnt);
}

vector<char> used_char;

int main()
{
	int N, total_N;
	string str;

	cin >> N >> str;
	vector<Token> tokens = tokenize(str);
	int res = 0, used_cnt, unused_cnt;
	char used_char_arr[26];
	for (int j = 0; j < N; j++)
		if (use[j])
			used_char.emplace_back(j);
	used_cnt = used_char.size();
	unused_cnt = N - used_cnt;

	Node *ast;
	p_exoression(tokens.begin(), tokens.end(), &ast);

	// total_N = 1 << (N);
	// for (int i = 0; i < total_N; i++)
	// {
	// 	if (check[i] == 0)
	// 	{
	// 		bzero(use, 26);
	// 		g_case_num = i;
	// 		tmp_res = ast->eval();
	// 		if (tmp_res == 0)
	// 		{
	// 			int un_used_cnt = 0;
	// 			for (int j = 0; j < N; j++)
	// 				if (!use[j])
	// 				{
	// 					used_char_arr[un_used_cnt] = j;
	// 					un_used_cnt++;
	// 				}
	// 			for (int j = 0; j < (1 << un_used_cnt); j++)
	// 			{
	// 				int tmp_i = i;
	// 				for (int k = 0; k < un_used_cnt; k++)
	// 				{
	// 					if (j & (1 << k))
	// 						tmp_i |= (1 << used_char_arr[k]);
	// 				}
	// 				check[tmp_i] = 1;
	// 			}
	// 			cout << un_used_cnt << '\n';
	// 			res += 1 << un_used_cnt;
	// 		}
	// 		// cout << '\n';
	// 	}
	// }
	// cout << res << '\n';
}