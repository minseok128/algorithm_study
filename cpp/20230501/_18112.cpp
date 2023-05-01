#include <iostream>
#include <vector>
#include <queue>
using namespace std;

unsigned short get_msb(unsigned short n)
{
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n = n + 1;
	return (n >> 1);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	unsigned short start = 0, end = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		start <<= 1;
		start |= str[i] - '0';
	}
	//cout << get_msb(start);
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		end <<= 1;
		end |= str[i] - '0';
	}

	char check[1024] = {0};
	queue<int> q;
	q.push(start);
	check[start] = 1;
	while(!q.empty())
	{
		int crr = q.front();
		q.pop();

		if (crr == end)
		{
			cout << (int)check[crr] - 1 << '\n';
			return (0);
		}
		for (int i = 0; i < 3; i++)
		{
			unsigned short new_i = crr;
			if (i == 0)
			{
				unsigned short msb = get_msb(crr);
				for (int j = 1; j < msb; j <<= 1)
				{
					new_i = crr ^ j;
					if (check[new_i] == 0)
					{
						check[new_i] = check[crr] + 1;
						q.push(new_i);
					}
				}
			}
			else
			{
				new_i += i == 1 ? 1 : -1;
				if (new_i < 1024 && check[new_i] == 0)
				{
					check[new_i] = check[crr] + 1;
					q.push(new_i);
				}
			}
		}
	}
}