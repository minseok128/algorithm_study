#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	long long x, y;
} Point;

typedef struct
{
	Point p1, p2;
} Line;

int CCW(Point a, Point b, Point c)
{
	long long s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (s < 0)
		return (-1);
	return (s > 0);
}

int compare(Point *a, Point *b)
{
	if (a->x > b->x)
	{
		return (1);
	}
	else if (a->x == b->x)
	{
		if (a->y > b->y)
			return (1);
		if (a->y == b->y)
			return (2);
	}
	return (0);
}

void swap(Point *a, Point *b)
{
	Point tmp;
	if (compare(a, b))
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int cross(Line *l1, Line *l2)
{
	Point a = l1->p1;
	Point b = l1->p2;
	Point c = l2->p1;
	Point d = l2->p2;

	int p1 = CCW(a, b, c) * CCW(a, b, d);
	int p2 = CCW(c, d, a) * CCW(c, d, b);
	if (compare(&b, &c) == 2 || compare(&a, &d) == 2)
		return (1);
	if (compare(&a, &c) == 2)
	{
		if (a.x == b.x && a.x == d.x && b.x == d.x)
			return (3);
		if ((b.y - a.y) * (d.x - a.x) == (d.y - a.y) * (b.x - a.x))
			return (3);
		return (1);
	}
	if (compare(&b, &d) == 2)
	{
		if ((b.y - a.y) * (b.x - c.x) == (b.y - c.y) * (b.x - a.x))
			return (3);
		return (1);
	}
	if (p1 == 0 && p2 == 0)
	{
		if (compare(&b, &c) && compare(&d, &a))
			return (3);
		else
			return (0);
	}
	else if (CCW(a, b, c) == 0)
	{
		if (compare(&c, &a) && compare(&b, &c))
			return (4);
		else
			return (0);
	}
	else if (CCW(a, b, d) == 0)
	{
		if (compare(&d, &a) && compare(&b, &d))
			return (4);
		else
			return (0);
	}
	else if (CCW(c, d, a) == 0)
	{
		if (compare(&a, &c) && compare(&d, &a))
			return (4);
		else
			return (0);
	}
	else if (CCW(c, d, b) == 0)
	{
		if (compare(&b, &c) && compare(&d, &b))
			return (4);
		else
			return (0);
	}
	else if (p1 == -1 && p2 == -1)
		return (2);
	else
		return (0);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	Line l1, l2;
	cin >> l1.p1.x >> l1.p1.y >> l1.p2.x >> l1.p2.y;
	cin >> l2.p1.x >> l2.p1.y >> l2.p2.x >> l2.p2.y;
	swap(&(l1.p1), &(l1.p2));
	swap(&(l2.p1), &(l2.p2));
	int result = cross(&l1, &l2);
	if (result == 1)
	{
		if (compare(&(l1.p1), &(l2.p1)) == 2 || compare(&(l1.p1), &(l2.p2)) == 2)
			cout << "1\n"
				 << l1.p1.x << " " << l1.p1.y << '\n';
		else
			cout << "1\n"
				 << l1.p2.x << " " << l1.p2.y << '\n';
	}
	else if (result == 2 || result == 4)
	{
		long long a, b, c, d, e, f;
		a = l1.p2.y - l1.p1.y;
		b = l1.p1.x - l1.p2.x;
		e = (l1.p2.y - l1.p1.y) * l1.p1.x - (l1.p2.x - l1.p1.x) * l1.p1.y;
		c = l2.p2.y - l2.p1.y;
		d = l2.p1.x - l2.p2.x;
		f = (l2.p2.y - l2.p1.y) * l2.p1.x - (l2.p2.x - l2.p1.x) * l2.p1.y;
		long double x, y;
		x = (e * d - b * f) / (long double)(a * d - b * c);
		y = (a * f - e * c) / (long double)(a * d - b * c);
		cout.precision(17);
		cout << "1\n"
			 << x << " " << y << '\n';
	}
	else if (result == 3)
		cout << "1\n";
	else
		cout << "0\n";
}