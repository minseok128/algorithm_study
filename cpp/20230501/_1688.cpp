#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct
{
	long long x, y;
} Point;

typedef struct
{
	Point p1, p2;
} Line;

int N;
vector<Line> lArr;

void swap(Line *a)
{
	Point *tmp;
	if (a->p1.x > a->p2.x)
	{
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	vector<Point> pArr(N + 1);
	for (int i = 0; i < N; i++)
		cin >> pArr[i].x >> pArr[i].y;
	pArr[N] = pArr[0];

	lArr = vector<Line>(N);
	for (int i = 0; i < N; i++)
	{
		lArr[i].p1 = pArr[i];
		lArr[i].p2 = pArr[i + 1];
	}
}