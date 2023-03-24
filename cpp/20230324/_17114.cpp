#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int input[11], delta[12];
int box_size = 1, tomato_count, day;
vector<int> box;

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

		for (int i = 0; i < 22; i++)
		{
			int sign = i % 2 ? 1 : -1;
			int new_i = crr + delta[i / 2] * sign;
			if (new_i >= 0 && new_i < box_size)
			{
				if (new_i / delta[i / 2 + 1] == crr / delta[i / 2 + 1] && box[new_i] == 0)
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

	for (int i = 0; i < 11; i++)
	{
		cin >> input[i];
		box_size *= input[i];
	}
	delta[11] = box_size;
	for (int i = 10; i >= 0; i--)
		delta[i] = delta[i + 1] / input[i];
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
