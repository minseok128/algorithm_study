#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<pair<int,int>> map;
int N;


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	if (N == 1)
		cout << "0\n1\n";
	map = vector<pair<int, int>>(N + 1, make_pair(2147483647, 0));
	map[N].first = 0;
	map[N].second = N + 1;

	queue<int> q;

	q.push(N);
	
	while (!q.empty())
	{
		int crr = q.front();
		q.pop();
		
		for (int i = 0; i < 3; i++)
		{
			int new_idx = 0;
			if (i == 0)
				new_idx = crr - 1;
			else if (i == 1 && crr % 2 == 0)
				new_idx = crr / 2;
			else if (i == 2 && crr % 3 == 0)
				new_idx = crr / 3;
			if (new_idx < 0)
				continue ;
			if (map[crr].first + 1 < map[new_idx].first)
			{
				map[new_idx].first = map[crr].first + 1;
				map[new_idx].second = crr;

				if (new_idx == 1)
				{
					cout << map[1].first << '\n';
					stack<int> s;
					for (int k = 1; k <= N; k = map[k].second)
					{
						s.push(k);
					}
					while (!s.empty())
					{
						int k = s.top();
						s.pop();
						cout << k << ' ';	
					}
					return (0);
				}
				q.push(new_idx); 
			}
		}
	}
}