#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct compare
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return (a > b);
		if (abs(a) < abs(b))
			return (0);
		else
			return (1);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	priority_queue<int, vector<int>, compare> pq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
		{
			pq.push(tmp);
		}
	}
}