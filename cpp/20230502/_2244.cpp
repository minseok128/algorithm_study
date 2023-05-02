#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct point
{
	long long x, y;
} Point;

int n, m;
vector<Point> arr;
Point sp = {(1 << 30), (1 << 30)};

int ccw(Point *a, Point *b, Point *c)
{
	long long s = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);
	if (s < 0)
		return (-1);
	return (s > 0);
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
		if (a.x == b.x)
			return (a.y < b.y);
		return (a.x > b.x);
	}
	return (ar > br);
}

int compare_same(Point a, Point b)
{
	return (a.x == b.x && a.y == b.y);
}

void convex()
{
	stack<Point> s;
	s.push(arr[0]);
	s.push(arr[1]);

	Point p1, p2;
	for (int i = 2; i < arr.size() && !s.empty(); i++)
	{
		p2 = s.top();
		s.pop();
		p1 = s.top();
		int c = ccw(&p1, &p2, &arr[i]);
		if (c == -1)
		{
			s.push(p2);
			s.push(arr[i]);
		}
		else if (c == 1)
			i--;
		else if ((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x) > (p1.y - arr[i].y) * (p1.y - arr[i].y) + (p1.x - arr[i].x) * (p1.x - arr[i].x))
			s.push(p2);
		else
			s.push(arr[i]);
	}
	cout << s.size() - 1 << '\n';
	while (s.size() > 1)
	{
		p1 = s.top();
		s.pop();
		cout << p1.x << " " << p1.y << '\n';
	}
}

int main()
{
	Point tmp;
	int new_id;

	cin >> n >> m;
	vector<Point> tmp_arr(n);
	for (int i = 0; i < n; i++)
		cin >> tmp_arr[i].x >> tmp_arr[i].y;
	arr.resize(m * n);
	for (int i = 0; i < m; i++)
	{
		cin >> tmp.x >> tmp.y;
		for (int j = 0; j < n; j++)
		{
			new_id = i * n + j;
			arr[new_id].x = tmp_arr[j].x + tmp.x;
			arr[new_id].y = tmp_arr[j].y + tmp.y;
			if (sp.x > arr[new_id].x || (sp.x == arr[new_id].x && sp.y > arr[new_id].y))
				sp = arr[new_id];
		}
	}
	sort(arr.begin(), arr.end(), &compare);
	arr.erase(unique(arr.begin(), arr.end(), compare_same), arr.end());
	arr.emplace_back(sp);
	convex();
}