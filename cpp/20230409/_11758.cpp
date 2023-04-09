#include <iostream>
using namespace std;

typedef struct {
	int x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	int s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (s < 0)
		return (-1);
	return (s > 0);
}

int main()
{
	Point a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	cout << CCW(a, b, c);
}