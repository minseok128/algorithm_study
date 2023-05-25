#include <iostream>
#include <vector>
#include <stack> 
#include <bitset>
#include <cmath>
using namespace std;

typedef struct {
	int y, x, depth;
	bitset<26> bits;
} Node;

int N, M, res = 1, dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
vector<vector<char>> map;

int main ()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	map = vector<vector<char>>(N + 2, vector<char>(M + 2));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	
	stack<Node> s;
	Node crr = {1, 1, 1};
	crr.bits.set(map[1][1] - 'A', 1);
	s.push(crr);

	while (!s.empty())
	{
		crr = s.top();
		s.pop();
		//cout << crr.y << ' ' << crr.x << ' ' << crr.bits.to_string() << '\n';
		for (int i = 0; i < 4; i++)
		{
			int new_y = crr.y + dy[i], new_x = crr.x + dx[i];
			if (map[new_y][new_x] && !crr.bits[map[new_y][new_x] - 'A'])
			{
				Node new_node = {new_y, new_x, crr.depth + 1};
				new_node.bits = crr.bits;
				new_node.bits.set(map[new_y][new_x] - 'A', 1);
				s.push(new_node);

				res = max(res, new_node.depth);
			}
		}
	}
	cout << res;
}