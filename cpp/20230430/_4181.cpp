#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct
{
	long long x, y;
} Point;

int N;
Point sp;
vector<Point> arr;

int compare(Point a, Point b)
{
	double ar, br;
	ar = atan2(a.y - sp.y, a.x - sp.x);
	br = atan2(b.y - sp.y, b.x - sp.x);
	if (a.x == sp.x && a.y == sp.y)
		return (1);
	if (b.x == sp.x && b.y == sp.y)
		return (0);
	if (ar == br)
	{
		if (ar > atan2(1, 1))
		{
			if (a.x == b.x)
				return (a.y > b.y);
			return (a.x > b.x);
		}
		else
		{
			if (a.x == b.x)
				return (a.y < b.y);
			return (a.x < b.x);
		}
	}
	return (ar < br);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	sp.y = 1000000000;
	sp.x = 1000000000;
	cin >> N;
	Point np;
	char c;
	for (int i = 0; i < N; i++)
	{
		cin >> np.x >> np.y >> c;
		if (c == 'Y')
		{
			arr.emplace_back(np);
			if (np.x < sp.x || (np.x == sp.x && np.y < sp.y))
				sp = np;
		}
	}
	sort(arr.begin(), arr.end(), compare);
	cout << arr.size() << '\n';

	int flag = 0, flag2 = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (i)
		{
			double r1 = atan2(arr[i].y - sp.y, arr[i].x - sp.x);
			double r2 = atan2(arr[i - 1].y - sp.y, arr[i - 1].x - sp.x);
			if (r1 == r2 && r1 != atan2(1, 1))
				flag = 1;
			int j = 0;
			while (r1 == atan2(1, 1) && flag && !flag2 && i < N)
			{
				j++;
				r1 = atan2(arr[i + j].y - sp.y, arr[i + j].x - sp.x);
			}
			if (j)
			{
				reverse(arr.begin() + i, arr.begin() + i + j);
				flag2 = 1;
			}
		}
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
}