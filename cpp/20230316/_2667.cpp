#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	string S;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = S[j] - '0';
		}
	}

	stack<pair<int, int>> s;
	vector<int> island_size;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1)
			{
				count++;
				int size = 0;
				s.push(make_pair(i, j));
				while (!s.empty())
				{
					pair<int, int> crr = s.top();
					s.pop();
					if (arr[crr.first][crr.second] == 1)
					{
						arr[crr.first][crr.second] = 0;
						size++;
						for (int k = 0; k < 4; k++)
						{
							int dy = k == 0 ? -1 : (k == 1 ? 1 : 0);
							int dx = k == 2 ? -1 : (k == 3 ? 1 : 0);
							if (crr.first + dy >= 0 && crr.first + dy < N && crr.second + dx >= 0 && crr.second + dx < N)
							{
								s.push(make_pair(crr.first + dy, crr.second + dx));
							}
						}
					}
				}
				island_size.push_back(size);
			}
		}
	}
	cout << count << '\n';
	sort(island_size.begin(), island_size.end());
	for (int i = 0; i < island_size.size(); i++)
		cout << island_size[i] << '\n';
}