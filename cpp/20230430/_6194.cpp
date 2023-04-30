#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
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

double convex()
{
	stack<Point> s;
	s.push(arr[0]);
	s.push(arr[1]);

	Point p1, p2;
	double res = 0;
	for (int i = 2; i <= N && !s.empty(); i++)
	{
		p2 = s.top();
		s.pop();
		p1 = s.top();
		int c = ccw(&p1, &p2, &arr[i]);
		if (c == 1)
		{
			s.push(p2);
			s.push(arr[i]);
		}
		else if (c == -1)
			i--;
		else if ((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x) > (p1.y - arr[i].y) * (p1.y - arr[i].y) + (p1.x - arr[i].x) * (p1.x - arr[i].x))
			s.push(p2);
		else
			s.push(arr[i]);
	}
	while (s.size() > 1)
	{
		p1 = s.top();
		s.pop();
		p2 = s.top();
		res += sqrt((p1.y - p2.y) * (p1.y - p2.y) + (p1.x - p2.x) * (p1.x - p2.x));
	}
	return (res);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	sp.y = 45001;
	sp.x = 45001;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		Point np;
		cin >> np.x >> np.y;
		arr.emplace_back(np);
		if (np.x < sp.x || (np.x == sp.x && np.y < sp.y))
			sp = np;
	}
	sort(arr.begin(), arr.end(), compare);
	arr.emplace_back(sp);
	cout << fixed;
	cout.precision(2);
	cout << convex() << '\n';
}