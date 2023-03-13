#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct node
{
	int id;
	bool isCheaked;
	vector<void *> nexts;
} Node;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, s, e, result = -1;
	stack<Node *> stack;

	cin >> N >> M;
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
	stack.push(&nodes[1]);
	while (!stack.empty())
	{
		Node *crr = stack.top();
		stack.pop();
		if (!(crr->isCheaked))
		{
			crr->isCheaked = true;
			result++;
			for (int i = 0; i < crr->nexts.size(); i++)
			{
				stack.push((Node *)crr->nexts[i]);
			}
		}
	}
	cout << result << '\n';
	return (0);
}