#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n, o, p, q, r, s, t, u, v, w, box_size, tomato_count, day = 0;
vector<int> box;
vector<int> delta(11);

void bfs()
{
	queue<int> q;

	for (int i = 0; i < box_size; i++)
	{
		if (box[i] == 1)
			q.push(i);
	}

	while (!q.empty())
	{
		int crr = q.front();
		q.pop();

		for(int i = 0; i < 22; i++)
		{
			int sign = i % 2 ? 1 : -1;
			int new_i = crr + delta[i / 2] * sign;
			//cout << "crr:" << crr << " new_i:" << new_i << '\n';
			if (new_i >= 0 && new_i < box_size)
			{
				if (i < 2 && (new_i / m != crr / m))
				{
					//cout << "firbiden:" << " new_i:" << new_i << '\n';
					continue ;
				}
				if (box[new_i] == 0)
				{
					tomato_count--;
					box[new_i] = box[crr] + 1;
					q.push(new_i);
					day = max(day, box[new_i]) - 1;
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
	box_size = m * n * o * p * q * r * s * t * u * v * w;
	delta[10] = m * n * o * p * q * r * s * t * u * v;
	delta[9] = m * n * o * p * q * r * s * t * u;
	delta[8] = m * n * o * p * q * r * s * t;
	delta[7] = m * n * o * p * q * r * s;
	delta[6] = m * n * o * p * q * r;
	delta[5] = m * n * o * p * q;
	delta[4] = m * n * o * p;
	delta[3] = m * n * o;
	delta[2] = m * n;
	delta[1] = m;
	delta[0] = 1;
	//reverse(delta.begin(), delta.end());
	box = vector<int>(box_size);

	for (int i = 0; i < box_size; i++)
	{
		cin >> box[i];
		if (box[i] == 0)
			tomato_count++;
	}

	bfs();
	if (tomato_count == 0)
		cout << day << '\n';
	else
		cout << "-1\n";
}
