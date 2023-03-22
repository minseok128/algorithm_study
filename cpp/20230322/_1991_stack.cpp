#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct node {
	char id;
	struct node *left;
	struct node *right;
}	Node;

int N;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> N;
	vector<Node> tree(N);
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].id = a;
		tree[a - 'A'].left = tree[a - 'A'].right = NULL;
		if (b != '.')
			tree[a - 'A'].left = &tree[b - 'A'];
		if (c != '.')
			tree[a - 'A'].right = &tree[c - 'A'];
	}

	stack<Node *> s;
	s.push(&tree[0]);
	while (!s.empty())
	{
		Node *crr = s.top();
		s.pop();

		cout << crr->id;
		if (crr->right)
			s.push(crr->right);
		if (crr->left)
			s.push(crr->left);
	}
	cout << '\n';

	Node *crr = &tree[0];
	while (!s.empty() || crr != NULL)
	{
		if (crr != NULL)
		{
			s.push(crr);
			crr = crr->left;
		}
		else
		{
			crr = s.top();
			s.pop();
			cout << crr->id;
			crr = crr->right;
		}
	}
	cout << '\n';

	stack<char> out;
	s.push(&tree[0]);
	while (!s.empty())
	{
		crr = s.top();
		s.pop();

		out.push(crr->id);

		if (crr->left)
			s.push(crr->left);
		if (crr->right)
			s.push(crr->right);
	}

	while (!out.empty())
	{
		cout << out.top();
		out.pop();
	}
	cout << '\n';
}
