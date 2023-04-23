#include <iostream>
#include <vector>
#include <stack>
using namespace std;

char seq[27];
vector<char> info;
char cube[3][3][3];
char dZYX[3][3][6] = {{{0, 0, 0, 0, 1, -1}, {0, 0, 1, -1, 0, 0}, {0, 0, 0, 0, 0, 0}},
					{{0, 0, 0, 0, 1, -1}, {0, 0, 0, 0, 0, 0}, {1, -1, 0, 0, 0, 0}},
					{{0, 0, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0},{1, -1, 0, 0, 0, 0}}};

typedef struct pos {
	char z, y, x, d;
	pos(char Z, char Y, char X, char D) : z(Z), y(Y), x(X), d(D){};
} Pos;

void make_info()
{
	for (int i = 0; i < 14; i++)
		for (int j  = 0; j < 2; j++)
			seq[i * 2 + j] = 65 + j * 32 + i;
	
	vector<vector<char>> map(17, vector<char>(17, '.'));
	int sy, sx;
	string str;
	for (int i = 1; i < 16; i++)
	{
		cin >> str;
		for (int j = 0; j < 15; j++)
		{
			map[i][j + 1] = str[j];
			if (str[j] == 65)
			{
				sy = i;
				sx = j + 1;
			}
		}
	}
	int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1}, size = -1, next_num = 1;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (map[sy + dy[i]][sx + dx[i]] == seq[next_num])
			{
				size++;
				info.emplace_back(1);
				next_num++;
				sy += dy[i];
				sx += dx[i];
				if (map[sy + dy[i]][sx + dx[i]] == seq[next_num])
				{
					info[size]++;
					next_num++;
					sy += dy[i];
					sx += dx[i];
				}
				break;
			}
		}
		if (next_num == 27)
			break ;
	}
}

void recursive(int num, int info_num, Pos p)
{
	if (num == 28)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				for(int k = 0; k < 3; k++)
				{
					cout << seq[(int)cube[k][j][i] - 1];
				}
				if (j != 2)
					cout << ' ';
			}
			if (i != 2)
				cout << '\n';
		}
		exit(0);
	}
	if (info[info_num] == 1)
	{
		for (int i = 0; i < 6; i++)
		{
			Pos new_p(p.z + dZYX[p.d][0][i], p.y + dZYX[p.d][1][i], p.x + dZYX[p.d][2][i], i / 2);
			if (new_p.z >= 0 && new_p.z < 3 && new_p.y >= 0 && new_p.y < 3 && new_p.x >= 0 && new_p.x < 3)
			{
				if (cube[new_p.z][new_p.y][new_p.x] == 0)
				{
					cube[new_p.z][new_p.y][new_p.x] = num;
					recursive(num + 1, info_num + 1, new_p);
					cube[new_p.z][new_p.y][new_p.x] = 0;
				}
			}
		}
	}
	else if (info[info_num] == 2)
	{
		for (int i = 0; i < 6; i++)
		{
			Pos new_p1(p.z + dZYX[p.d][0][i], p.y + dZYX[p.d][1][i], p.x + dZYX[p.d][2][i], i / 2);
			Pos new_p2(p.z + dZYX[p.d][0][i] * 2, p.y + dZYX[p.d][1][i] * 2, p.x + dZYX[p.d][2][i] * 2, i / 2);
			if (new_p2.z >= 0 && new_p2.z < 3 && new_p2.y >= 0 && new_p2.y < 3 && new_p2.x >= 0 && new_p2.x < 3)
			{
				if (cube[new_p1.z][new_p1.y][new_p1.x] == 0 && cube[new_p2.z][new_p2.y][new_p2.x] == 0)
				{
					cube[new_p1.z][new_p1.y][new_p1.x] = num;
					cube[new_p2.z][new_p2.y][new_p2.x] = num + 1;
					recursive(num + 2, info_num + 1, new_p2);
					cube[new_p1.z][new_p1.y][new_p1.x] = 0;
					cube[new_p2.z][new_p2.y][new_p2.x] = 0;
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	make_info();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				cube[i][j][k] = 1;
				recursive(2, 0, Pos(i, j, k, 2));
				cube[i][j][k] = 0;
			}
		}
	}
}
