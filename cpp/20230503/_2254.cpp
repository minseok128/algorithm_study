#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct {
	long long y, x;
} Point; 

int n;
Point P, sp;
vector<Point> arr;

Point find_sp()
{
	Point res = {100001, 100001};
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].y < res.y || (arr[i].y == res.y && arr[i].x < res.x))
			res = arr[i];
	}
	return (res);
}

int compare(Point a, Point b)
{
	if (a.x == sp.x && a.y == sp.y)
		return (1);
	if (b.x == sp.x && b.y == sp.y)
		return (0);
	double ar, br;
	ar = atan2(a.y - sp.y, a.x - sp.x);
	br = atan2(b.y - sp.y, b.x - sp.x);
	if (ar == br)
	{
		if (a.y == b.y)
			return (a.x > b.x);
		return (a.y < b.y);
	}
	return (ar < br);
}

int ccw(Point *a, Point *b, Point *c)
{
	long long s = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);
	if (s < 0)
		return (-1);
	return (s > 0);
}

long long get_length(Point *a, Point *b)
{
	return ((a->y - b->y) * (a->y - b->y) + (a->x - b->x) * (a->x - b->x));
}

void convex()
{
	vector<Point> con(arr.size());
	int cnt = 1, prev, c;

	con[0] = arr[0];
	con[1] = arr[1];
	for (int i = 2; i < arr.size(); i++)
	{
		//cout << "arrsize:" << arr.size() << '\n';
		prev = cnt - 1 > 0 ? cnt - 1 : 0;
		c = ccw(&con[cnt - 1], &con[cnt], &arr[i]);
		if (c == 1)
			con[++cnt] = arr[i];
		else if (c == -1)
		{
			i--;
			cnt--;
		}
		else if (get_length(&con[prev], &con[cnt]) < get_length(&con[prev], &arr[i]))
			con[cnt] = arr[i];
	}
	//for (int i = 0; i < cnt; i++)
	//	cout << con[i].x << "," << con[i].y << "  ";
	cout << cnt << '\n';
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> P.x >> P.y;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	sp = find_sp();
	sort(arr.begin(), arr.end(), compare);
	arr.emplace_back(sp);

	cout << "sp " << sp.x << "," << sp.y << '\n';
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i].x << "," << arr[i].y << "  ";
	convex();
}