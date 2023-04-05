#include <iostream>
using namespace std;

char input[27];
int info[6][4][2] = {{{1, 0}, {2, 0}, {3, 0}, {4, 0}}, {{0, 0}, {4, 4}, {5, 7}, {2, 3}}, {{0, 3}, {1, 4}, {5, 3}, {3, 3}}, {{0, 7}, {2, 4}, {5, 0}, {4, 3}}, {{0, 4}, {3, 4}, {5, 4}, {1, 3}}, {{2, 6}, {1, 6}, {4, 6}, {3, 6}}};
int info_side[8][3] = {{0, 1, 2}, {2, 1, 0}, {0, 3, 6}, {6, 3, 0}, {2, 5, 8}, {8, 5, 2}, {6, 7, 8}, {8, 7, 6}};
char cube[6][9];
int rot_info[8] = {0, 1, 2, 5, 8, 7, 6, 3};

void cubing(int n, char r)
{
	int sign = r == '+' ? -1 : 1;
	int i = r == '+' ? 7 : 0;
	char tmp1 = cube[n][rot_info[i]];
	char tmp2 = cube[n][rot_info[i + sign]];
	for (int j = 0; j < 6; j++)
		cube[n][rot_info[i + j * sign]] = cube[n][rot_info[i + (j + 2) * sign]];
	cube[n][rot_info[7 - i - sign]] = tmp1;
	cube[n][rot_info[7 - i]] = tmp2;

	i = r == '+' ? 0 : 3;
	sign = r == '+' ? 1 : -1;
	char tmpA[3];
	for (int j = 0; j < 3; j++)
		tmpA[j] = cube[info[n][i][0]][info_side[info[n][i][1]][j]];
	for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++)
			cube[info[n][i + j * sign][0]][info_side[info[n][i + j * sign][1]][k]] = cube[info[n][i + (j + 1) * sign][0]][info_side[info[n][i + (j + 1) * sign][1]][k]];
	for (int j = 0; j < 3; j++)
		cube[info[n][3 - i][0]][info_side[info[n][3 - i][1]][j]] = tmpA[j];
}

void cube_set()
{
	for (int i = 0; i < 9; i++)
		cin >> cube[0][i];
	int side[] = {2, 3, 4, 1};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 12; j++)
			cin >> cube[side[j / 3]][3 * i + j % 3];
	for (int i = 0; i < 9; i++)
		cin >> cube[5][i];
}

void ptr_c(int n)
{
	cout << "Scenario #" << n << ":\n";
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			cout << "      ";
		cout << cube[0][i] << ' ';
		if (i % 3 == 2)
			cout << '\n';
	}
	int side[] = {2, 3, 4, 1};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
			cout << cube[side[j / 3]][3 * i + j % 3] << ' ';
		cout << '\n';
	}
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			cout << "      ";
		cout << cube[5][i] << ' ';
		if (i % 3 == 2)
			cout << '\n';
	}
	cout << '\n';
}

int main()
{
	int N, M, s, r, t;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cube_set();
		for (cin >> M; M > 0; M--)
		{
			cin >> s >> r;
			// left '0', front '1', right '2', back '3', top '4', bottom '5'.
			if (s == 1)
				s = 3;
			else if (s == 0)
				s = 2;
			else if (s == 2)
				s = 4;
			else if (s == 3)
				s = 1;
			else if (s == 4)
				s = 0;
			else if (s == 5)
				s = 5;
			if (r == -1)
				t = '-';
			else if (r == 1)
				t = '+';
			cubing(s, t);
		}
		ptr_c(i);
	}
}
