#include <iostream>
using namespace std;

typedef struct {
	long long x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	long long s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (s < 0)
		return (-1);
	return (s > 0);
}

int compare(Point *a, Point *b)
{
	return (a->x > b->x || (a->x == b->x && a->y >= b->y));
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

int main()
{
	Point a, b, c, d;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	cin >> d.x >> d.y;
	swap(&a, &b);
	swap(&c, &d);

	int p1 = CCW(a, b, c) * CCW(a, b, d);
	int p2 = CCW(c, d, a) * CCW(c, d, b);
	if (p1 == 0 && p2 == 0)
	{
		cout << "this";
		if (compare(&b, &c) && compare(&d, &a))
			cout << "1\n";
		else
			cout << "0\n";
	}
	else if(CCW(a, b, c) == 0)
	{
		if (compare(&c, &a) && compare(&b, &c))
			cout << "1\n";
		else
			cout << "0\n";
	}
	else if(CCW(a, b, d) == 0)
	{
		if (compare(&d, &a) && compare(&b, &d))
			cout << "1\n";
		else
			cout << "0\n";
	}
	else if(CCW(c, d, a) == 0)
	{
		if (compare(&a, &c) && compare(&d, &a))
			cout << "1\n";
		else
			cout << "0\n";
	}
	else if(CCW(c, d, b) == 0)
	{
		if (compare(&b, &c) && compare(&d, &b))
			cout << "1\n";
		else
			cout << "0\n";
	}
	else if (p1 == -1 && p2 == -1)
		cout << "1\n";
	else
		cout << "0\n";
}