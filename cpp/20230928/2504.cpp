#include <iostream>
#include <vector>
using namespace std;

typedef enum {
	PAR_OPEN = 0,
	PAR_CLOSE = 1,
	PAR_PAIR = 2,
	BRA_OPEN = 3,
	BRA_CLOSE = 4,
	BRA_PAIR = 5,
} TokenType;

using Tokensit = vector<TokenType>::iterator;

struct Node {
	virtual int	eval(void) = 0;
};

struct ParPair : public Node {
	virtual int	eval(void)
	{
		return (2);
	}
};

struct BraPair : public Node {
	virtual int	eval(void)
	{
		return (3);
	}
};

struct Concat : public Node {
	Node	*left, *right;
	Concat(Node *l, Node *r) : left(l), right(r) {};
	virtual int	eval(void)
	{
		return (this->left->eval() + this->right->eval());
	}
};

struct EnclPar : public Node {
	Node	*child;
	EnclPar(Node *c) : child(c) {};
	virtual int	eval(void)
	{
		return (this->child->eval() * 2);
	}
};

struct EnclBra : public Node {
	Node	*child;
	EnclBra(Node *c) : child(c) {};
	virtual int	eval(void)
	{
		return (this->child->eval() * 3);
	}
};

vector<TokenType> tokenize(string str)
{
	vector<TokenType> res;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ')')
			res.emplace_back(PAR_CLOSE);
		else if (str[i] == ']')
			res.emplace_back(BRA_CLOSE);
		else if (str[i] == '(')
		{
			if (str[i + 1] == ')')
			{
				res.emplace_back(PAR_PAIR);
				i++;
			}
			else
				res.emplace_back(PAR_OPEN);
		}
		else if (str[i] == '[')
		{
			if (str[i + 1] == ']')
			{
				res.emplace_back(BRA_PAIR);
				i++;
			}
			else
				res.emplace_back(BRA_OPEN);
		}
	}
	return (res);
}

// <S>	::=	("()" | "[]" | "(" <S> ")" | "[" <S> "]") <S>?

int parse(Tokensit it_begin, Tokensit it_end, Node **ast)
{
	int token_cnt = 0, tmp;
	Node *left, *right;
	if (*it_begin == PAR_PAIR)
	{
		token_cnt++;
		left = new ParPair();
	}
	else if(*it_begin == BRA_PAIR)
	{
		token_cnt++;
		left = new BraPair();
	}
	else if(*it_begin == PAR_OPEN)
	{
		token_cnt++;
		tmp = parse(it_begin + 1, it_end, &left);
		if (tmp < 0)
			return (-1);
		token_cnt += tmp;
		if (it_begin + token_cnt != it_end && *(it_begin + token_cnt) != PAR_CLOSE)
			return (-1);
		token_cnt++;
		left = new EnclPar(left);
	}
	else if(*it_begin == BRA_OPEN)
	{
		token_cnt++;
		tmp = parse(it_begin + 1, it_end, &left);
		if (tmp < 0)
			return (-1);
		token_cnt += tmp;
		if (it_begin + token_cnt != it_end && *(it_begin + token_cnt) != BRA_CLOSE)
			return (-1);
		token_cnt++;
		left = new EnclBra(left);
	}
	else
		return (-1);
	tmp = parse(it_begin + token_cnt, it_end, &right);
	if (tmp >= 0)
	{
		token_cnt += tmp;
		*ast = new Concat(left, right);
	}
	else
		*ast = left;
	return (token_cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	vector<TokenType> tokens = tokenize(str);
	Node *ast;
	int token_cnt = parse(tokens.begin(), tokens.end(), &ast);
	if (token_cnt >= 0 && token_cnt == (int)tokens.size())
		cout << ast->eval() << '\n';
	else
		cout << 0 << '\n';
}