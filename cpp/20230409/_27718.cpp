#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	long long x, y;
} Point;

typedef struct {
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
	//cout << "here" <<  a.x << a.y << b.x << b.y << '\n';
	if (compare(&b, &c) == 2 || compare(&a, &d) == 2)
	{
		return (1);
	}
	if (compare(&a, &c) == 2)
	{
		if (a.x == b.x && a.x == d.x && b.x == d.x)
		{
			//if (d.y >= a.y && d.y < b.y)
				return (3);
			//return (1);
		}
		//cout << "here" <<  (b.y - a.y) * (d.x - a.x) << " " << (d.y - a.y) * (b.x - a.x) << '\n';
		if((b.y - a.y) * (d.x - a.x) == (d.y - a.y) * (b.x - a.x))
			return (3);
		return (1);
	}
	if (compare(&b, &d) == 2)
	{
		//if (a.x == b.x && a.x == c.x && b.x == c.x)
		//	return (1);
		//cout << "here" << '\n';
		if((b.y - a.y) * (b.x - c.x) == (b.y - c.y) * (b.x - a.x))
		{
			//if ()
			return (3);
		}
		return (1);
	}
	if (p1 == 0 && p2 == 0)
	{
		//if (compare(&a, &c) == 2 || compare(&b, &c) == 2)
		//{
		//	if (CCW(a, b, d) != 0)
		//		return (1);
		//	else
		//	{
		//		
		//	}
		//}
		//else if (compare(&a, &d) == 2 || compare(&b, &d) == 2)
		//{
		//	if (CCW(a, b, c) != 0)
		//	{
		//		return (1);
		//	}
		//}
		//if (compare())
		//	return (3);
		if (compare(&b, &c) && compare(&d, &a))
			return (3);
		else
			return (0);
	}
	else if(CCW(a, b, c) == 0)
	{
		if (compare(&c, &a) && compare(&b, &c))
			return (1);
		else
			return (0);
	}
	else if(CCW(a, b, d) == 0)
	{
		if (compare(&d, &a) && compare(&b, &d))
			return (1);
		else
			return (0);
	}
	else if(CCW(c, d, a) == 0)
	{
		if (compare(&a, &c) && compare(&d, &a))
			return (1);
		else
			return (0);
	}
	else if(CCW(c, d, b) == 0)
	{
		if (compare(&b, &c) && compare(&d, &b))
			return (1);
		else
			return (0);
	}
	else if (p1 == -1 && p2 == -1)
		return (2);
	else
		return (0);
}

char result[2000][2000];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	vector<Line> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].p1.x >> arr[i].p1.y >> arr[i].p2.x >> arr[i].p2.y;
		swap(&(arr[i].p1), &(arr[i].p2));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i == j)
				result[i][j] = 3 + '0';
			else
			{
				result[i][j] = result[j][i] = cross(&arr[i], &arr[j]) + '0';
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << result[i][j];
		cout << '\n';
	}
}