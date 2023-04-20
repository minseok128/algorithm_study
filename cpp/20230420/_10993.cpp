#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;
int n, w, hm, s;
void draw(int y, int h, int d)
{
	if (h == 0)
		return;
	for (int i = 0; i < h; i++)
		map[y + i * d][w / 2 + i] = map[y + i * d][w / 2 - i] = map[y + (h - 1) * d][w / 2 + i] = map[y + (h - 1) * d][w / 2 - i] = '*';
	draw(y + (h - 2) * d, (h + 1) / 2 - 1, d * -1);
}

int main()
{
	cin >> n;
	hm = (1 << n) - 1;
	w = (hm << 1) - 1;
	map = vector<vector<char>>(hm + 1, vector<char>(w + 1, ' '));
	s = n % 2 ? 1 : -1;
	draw(!(n % 2) * (hm - 1), hm, s);
	w = n % 2 ? w / 2 + 1 : w;
	for (int i = 0; i < hm; i++)
	{
		for (int j = 0; j < w + i * s; j++)
			cout << map[i][j];
		if (i != hm - 1)
			cout << '\n';
	}
}