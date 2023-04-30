#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	long double x, y;
} Point;

int N;
vector<Point> arr;

long double ccw(Point *a, Point *b, Point *c)
{
	return (a->x * b->y + b->x * c->y + c->x * a->y - b->x * a->y - c->x * b->y - a->x * c->y);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	arr = vector<Point>(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i].x >> arr[i].y;

	long double res = 0;
	for (int i = 1; i < N - 1; i++)
		res += ccw(&arr[0], &arr[i], &arr[i + 1]) / 2.0;
	if (res < 0)
		res *= -1;
	cout.precision(1);
	cout << fixed << res << '\n';
}