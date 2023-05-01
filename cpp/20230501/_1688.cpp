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

int N, max_x = 0;
vector<Line> lArr;

void swap(Line *a)
{
	Point tmp;
	if (a->p1.y > a->p2.y || (a->p1.y == a->p2.y && a->p1.x > a->p2.x))
	{
		tmp = a->p2;
		a->p2 = a->p1;
		a->p1 = tmp;
	}
}

int ccw(Point *a, Point *b, Point *c)
{
	long long s = (b->x - a->x) * (c->y - a->y) - (c->x - a->x) * (b->y - a->y);
	if (s < 0)
		return (-1);
	return (s > 0);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	vector<Point> pArr(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> pArr[i].x >> pArr[i].y;
		max_x = pArr[i].x > max_x ? pArr[i].x : max_x;
	}
	pArr[N] = pArr[0];

	lArr = vector<Line>(N);
	for (int i = 0; i < N; i++)
	{
		lArr[i].p1 = pArr[i];
		lArr[i].p2 = pArr[i + 1];
		swap(&lArr[i]);
	}
	Point man;
	for (int i = 0; i < 3; i++)
	{
		int cnt = 0, flag = 0;
		cin >> man.x >> man.y;
		if (man.x > max_x)
		{
			cout << "0\n";
			continue;
		}
		for (int j = 0; j < N; j++)
		{
			if (man.y < lArr[j].p1.y || man.y > lArr[j].p2.y)
				continue;
			if (lArr[j].p1.y == lArr[j].p2.y && (man.x < lArr[j].p1.x || man.x > lArr[j].p2.x))
				continue;
			if (ccw(&(lArr[j].p1), &(lArr[j].p2), &man) == 0)
			{
				flag = 1;
				break;
			}	
			if (ccw(&(lArr[j].p1), &(lArr[j].p2), &man) == 1)
			{
				if (man.y == lArr[j].p2.y)
				{
					int f = j != 0 ? j - 1 : N - 1; 
					int n = (j + 1) % N;
					if (man.y == lArr[f].p1.y || man.y == lArr[n].p1.y)
						cnt++;
				}
				else if (man.y != lArr[j].p1.y)
					cnt++;
			}
		}
		if (flag)
			cout << "1\n";
		else
			cout << (cnt % 2) << '\n';
	}
}