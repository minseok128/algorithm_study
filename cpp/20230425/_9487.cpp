#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
ofstream fout;
ifstream fin;

typedef struct
{
	long double x, y;
} Point;

typedef struct
{
	Point p1, p2;
} Line;

long long r, p, q, n, cnt, tmp;
Line arr[1001];

int CCW(Point a, Point b, Point c)
{
	long double s = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
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

void getInput()
{
	long double x1, y1, x2, y2, a, b, c;
	long double d;

	// cin >> x1 >> y1 >> x2 >> y2;
	fin >> x1 >> y1 >> x2 >> y2;
	a = y2 - y1;
	b = x1 - x2;
	c = (y2 - y1) * x1 - (x2 - x1) * y1;
	d = ((a * p + b * q + c) * (a * p + b * q + c)) / (long double)(a * a + b * b);
	if (d < r * r)
	{
		// cout << "\nd: " << d << '\n';
		// cout << "\na and b" << a << " " << b << "\n";
		//  arr[cnt].a = a;
		//  arr[cnt].b = b;
		//  arr[cnt].c = c;
		//  cnt++;

		long double A, B, C;
		A = 1 + (a * a) / (b * b);
		B = -2 * (p + (a * q) / b);
		C = p * p + (q - c / b) * (q - c / b) - r * r;
		x1 = (-1 * B + sqrt(B * B - 4 * A * C)) / 2 * A;
		y1 = (c - a * x1) / b;
		x2 = (-1 * B - sqrt(B * B - 4 * A * C)) / 2 * A;
		y2 = (c - a * x1) / b;
		arr[cnt].p1.x = x1;
		arr[cnt].p1.y = y1;
		arr[cnt].p2.x = x2;
		arr[cnt].p2.y = y1;
		cout << "here:" << x1 << " " << y1 << '\n';
		cout << "here:" << x2 << " " << y2 << '\n';
		swap(&(arr[cnt].p1), &(arr[cnt].p2));
		cnt++;
		// x = (-B ¡¾ sqrt(B^2 - 4AC)) / 2A
		// A = 1 + a^2 / b^2, B = -2(p + aq / b), C = p^2 + (q - c / b)^2 - r^2
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
			return (1);
		if ((b.y - a.y) * (d.x - a.x) == (d.y - a.y) * (b.x - a.x))
			return (1);
		return (1);
	}
	if (compare(&b, &d) == 2)
	{
		if ((b.y - a.y) * (b.x - c.x) == (b.y - c.y) * (b.x - a.x))
			return (1);
		return (1);
	}
	if (p1 == 0 && p2 == 0)
	{
		if (compare(&b, &c) && compare(&d, &a))
			return (1);
		else
			return (0);
	}
	else if (CCW(a, b, c) == 0)
	{
		if (compare(&c, &a) && compare(&b, &c))
			return (1);
		else
			return (0);
	}
	else if (CCW(a, b, d) == 0)
	{
		if (compare(&d, &a) && compare(&b, &d))
			return (1);
		else
			return (0);
	}
	else if (CCW(c, d, a) == 0)
	{
		if (compare(&a, &c) && compare(&d, &a))
			return (1);
		else
			return (0);
	}
	else if (CCW(c, d, b) == 0)
	{
		if (compare(&b, &c) && compare(&d, &b))
			return (1);
		else
			return (0);
	}
	else if (p1 == -1 && p2 == -1)
		return (1);
	else
		return (0);
}

// int isCrossInC(Line *l1, Line *l2)
// {
// 	if (l1->b / l1->a == l2->b / l2->a)
// 		return (0);
// 	long double x, y;
// 	long double d;
// 	x = ((l1->c * l2->b) - (l1->b * l2->c)) / (long double)(l1->a * l2->b - l1->b * l2->a);
// 	y = (l1->a * l2->c - l1->c * l2->a) / (long double)(l1->a * l2->b - l1->b * l2->a);
// 	// cout << l1->b << "|" << x << "|" << y << '\n';
// 	d = (x - p) * (x - p) + (y - q) * (y - q);
// 	if (d < r * r)
// 	{
// 		// cout << d << "here\n";
// 		//    		x = (e * d - b * f) / (long double)(a * d - b * c);
// 		//    		y = (a * f - e * c) / (long double)(a * d - b * c);
// 		return (1);
// 	}
// 	return (0);
// }

// int isCrossInC2(Line *l1, Line *l2)
// {
// 	long long x, y, x1, y1;
// 	unsigned long long d;
// 	x = ((l1->c * l2->b) - (l1->b * l2->c));
// 	x1 = (l1->a * l2->b - l1->b * l2->a);
// 	y = (l1->a * l2->c - l1->c * l2->a);
// 	y1 = (l1->a * l2->b - l1->b * l2->a);
// 	// cout << l1->b << "|" << x << "|" << y << '\n';
// 	d = (x - p * x1) * (x - p * x1) * y1 * y1 + (y - q * y1) * (y - q * y1) * x1 * x1;
// 	if (d <= r * r * x1 * x1 * y1 * y1)
// 	{
// 		cout << d << "here\n";
// 		//    		x = (e * d - b * f) / (long double)(a * d - b * c);
// 		//    		y = (a * f - e * c) / (long double)(a * d - b * c);
// 		return (1);
// 	}
// 	return (0);
// }

int main()
{
	fin.open("ju.txt");
	fout.open("my.txt");
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	while (1)
	{
		cnt = tmp = 0;
		// cin >> r >> p >> q >> n;
		fin >> r >> p >> q >> n;
		if (!(r || p || q || n))
			break;
		for (int i = 0; i < n; i++)
			getInput();
		for (int i = 0; i < cnt - 1; i++)
			for (int j = i + 1; j < cnt; j++)
			{
				// cout << "\nhere:" << i << ":" << j << ":" << arr[i].p1.x << '\n';
				tmp += cross(&arr[i], &arr[j]);
			}
		fout << cnt + tmp + 1 << "\n";
		// cout << cnt + tmp + 1 << "\n";
	}
	// for (int i = 0; i < cnt; i++)
	// 	cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << '\n';
}

// long long a, b, c, d, e, f;
// 		a = l1.p2.y - l1.p1.y;
// 		b = l1.p1.x - l1.p2.x;
// 		e = (l1.p2.y - l1.p1.y) * l1.p1.x - (l1.p2.x - l1.p1.x) * l1.p1.y;
// 		c = l2.p2.y - l2.p1.y;
// 		d = l2.p1.x - l2.p2.x;
// 		f = (l2.p2.y - l2.p1.y) * l2.p1.x - (l2.p2.x - l2.p1.x) * l2.p1.y;
// 		long double x, y;
// 		x = (e * d - b * f) / (long double)(a * d - b * c);
// 		y = (a * f - e * c) / (long double)(a * d - b * c);