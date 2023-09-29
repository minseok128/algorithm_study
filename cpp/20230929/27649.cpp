#include <iostream>
#include <vector>
using namespace std;

typedef enum
{
	BLANK,
	PAR_OPEN,
	PAR_CLOSE,
	OR_OPERATOR,
	AND_OPERATOR,
	REDICET_LEFT,
	REDIRECT_RIGHT,
	WORD,
} e_tokentype;

typedef struct s_token
{
	e_tokentype type;
	string value;
	s_token(e_tokentype t, string v = "") : type(t), value(v){};
} t_token;

int is_meta_char(char c)
{
	return (c == '<' || c == '>' || c == '(' || c == ')' || c == '&' || c == '|');
}

vector<t_token> tokenize(string s)
{
	vector<t_token> res;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
			res.emplace_back(t_token(REDICET_LEFT));
		else if (s[i] == '>')
			res.emplace_back(t_token(REDIRECT_RIGHT));
		else if (s[i] == '(')
			res.emplace_back(t_token(PAR_OPEN));
		else if (s[i] == ')')
			res.emplace_back(t_token(PAR_CLOSE));
		else if (s[i] == '&')
		{
			res.emplace_back(t_token(AND_OPERATOR));
			i++;
		}
		else if (s[i] == '|')
		{
			res.emplace_back(t_token(OR_OPERATOR));
			i++;
		}
		else if (!is_meta_char(s[i]) && s[i] != ' ')
		{
			int j = 1;
			while (!is_meta_char(s[i + j]) && s[i + j] != ' ' && i + j < s.size())
				j++;
			res.emplace_back(t_token(WORD, string(&s[i], &s[i + j])));
			i += j - 1;
		}
	}
	return (res);
}

void print_token(t_token t)
{
	if (t.type == BLANK)
		cout << " ";
	else if (t.type == PAR_OPEN)
		cout << "(";
	else if (t.type == PAR_CLOSE)
		cout << ")";
	else if (t.type == OR_OPERATOR)
		cout << "||";
	else if (t.type == AND_OPERATOR)
		cout << "&&";
	else if (t.type == REDICET_LEFT)
		cout << "<";
	else if (t.type == REDIRECT_RIGHT)
		cout << ">";
	else if (t.type == WORD)
		cout << t.value;
}

int main(void)
{
	string s;
	getline(cin, s);
	vector<t_token>
		tokens = tokenize(s);
	for (int i = 0; i < tokens.size(); i++)
	{
		print_token(tokens[i]);
		if (i < tokens.size() - 1)
			cout << ' ';
	}
}