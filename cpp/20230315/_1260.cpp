#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
	int id;
	bool isCheaked;
	vector<struct node *> nexts;
} Node;

bool node_compare0(Node *a, Node *b)
{
	if (a->id > b->id)
		return (true);
	else
		return (false);
}

bool node_compare1(Node *a, Node *b)
{
	if (a->id < b->id)
		return (true);
	else
		return (false);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, Start, s, e;
	stack<Node *> stack;
	queue<Node *> que;

	cin >> N >> M >> Start;
	vector<Node> nodes(N + 1);
	for (int i = 1; i <= N; i++)
	{
		nodes[i].id = i;
		nodes[i].isCheaked = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		nodes[s].nexts.push_back(&nodes[e]);
		nodes[e].nexts.push_back(&nodes[s]);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(nodes[i].nexts.begin(), nodes[i].nexts.end(), node_compare0);
	}
	stack.push(&nodes[Start]);
	while (!stack.empty())
	{
		Node *crr = stack.top();
		stack.pop();
		if (!(crr->isCheaked))
		{
			crr->isCheaked = true;
			cout << crr->id << " ";
			for (int i = 0; i < crr->nexts.size(); i++)
			{
				stack.push(crr->nexts[i]);
			}
		}
	}
	cout << "\n";
	for (int i = 1; i <= N; i++)
	{
		nodes[i].isCheaked = false;
	}
	for (int i = 1; i <= N; i++)
	{
		sort(nodes[i].nexts.begin(), nodes[i].nexts.end(), node_compare1);
	}
	que.push(&nodes[Start]);
	while (!que.empty())
	{
		Node *crr = que.front();
		que.pop();
		if (!(crr->isCheaked))
		{
			crr->isCheaked = true;
			cout << crr->id << " ";
			for (int i = 0; i < crr->nexts.size(); i++)
			{
				que.push(crr->nexts[i]);
			}
		}
	}
	return (0);
}