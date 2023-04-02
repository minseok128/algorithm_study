#include <iostream>
#include <cstring>
using namespace std;

char input[27];
char color[6] = {'w', 'o', 'g', 'r', 'b', 'y'};
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
	{
		for (int k = 0; k < 3; k++)
			cube[info[n][i + j * sign][0]][info_side[info[n][i + j * sign][1]][k]] = cube[info[n][i + (j + 1) * sign][0]][info_side[info[n][i + (j + 1) * sign][1]][k]];
	}
	for (int j = 0; j < 3; j++)
		cube[info[n][3 - i][0]][info_side[info[n][3 - i][1]][j]] = tmpA[j];
}

int main()
{
	input['U' - 'A'] = 0;
	input['B' - 'A'] = 1;
	input['L' - 'A'] = 2;
	input['F' - 'A'] = 3;
	input['R' - 'A'] = 4;
	input['D' - 'A'] = 5;
	int T;
	for (cin >> T; T > 0; T--)
	{
		for (int i = 0; i < 6; i++)
			memset(cube[i], color[i], 9);
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			cubing(input[str[0] - 'A'], str[1]);
		}
		for (int i = 0; i < 9; i++)
		{
			cout << cube[0][i];
			if (i % 3 == 2)
				cout << '\n';
		}
	}
	return (0);
}
