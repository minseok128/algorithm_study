#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;

typedef struct line
{
	long long a, b, c;
} Line;

long long r, cx, cy, n, cnt, tmp;
Line arr[1001];

void getInput()
{
	long long x1, y1, x2, y2, a, b, c;
	long double d;

	// cin >> x1 >> y1 >> x2 >> y2;
	fin >> x1 >> y1 >> x2 >> y2;
	a = y2 - y1;
	b = x1 - x2;
	c = (y2 - y1) * x1 - (x2 - x1) * y1;
	d = ((a * cx + b * cy + c) * (a * cx + b * cy + c)) / (long double)(a * a + b * b);
	if (d < r * r)
	{
		// cout << "\nd: " << d << '\n';
		// cout << "\na and b" << a << " " << b << "\n";
		arr[cnt].a = a;
		arr[cnt].b = b;
		arr[cnt].c = c;
		cnt++;
	}
}

int isCrossInC(Line *l1, Line *l2)
{
	long double x, y;
	long double d;
	x = ((l1->c * l2->b) - (l1->b * l2->c)) / (long double)(l1->a * l2->b - l1->b * l2->a);
	y = (l1->a * l2->c - l1->c * l2->a) / (long double)(l1->a * l2->b - l1->b * l2->a);
	// cout << l1->b << "|" << x << "|" << y << '\n';
	d = (x - cx) * (x - cx) + (y - cy) * (y - cy);
	if (d < r * r)
	{
		cout << d << "here\n";
		//   		x = (e * d - b * f) / (long double)(a * d - b * c);
		//   		y = (a * f - e * c) / (long double)(a * d - b * c);
		return (1);
	}
	return (0);
}

int isCrossInC2(Line *l1, Line *l2)
{
	long long x, y, x1, y1;
	unsigned long long d;
	x = ((l1->c * l2->b) - (l1->b * l2->c));
	x1 = (l1->a * l2->b - l1->b * l2->a);
	y = (l1->a * l2->c - l1->c * l2->a);
	y1 = (l1->a * l2->b - l1->b * l2->a);
	// cout << l1->b << "|" << x << "|" << y << '\n';
	d = (x - cx * x1) * (x - cx * x1) * y1 * y1 + (y - cy * y1) * (y - cy * y1) * x1 * x1;
	if (d <= r * r * x1 * x1 * y1 * y1)
	{
		cout << d << "here\n";
		//    		x = (e * d - b * f) / (long double)(a * d - b * c);
		//    		y = (a * f - e * c) / (long double)(a * d - b * c);
		return (1);
	}
	return (0);
}

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
		// cin >> r >> cx >> cy >> n;
		fin >> r >> cx >> cy >> n;
		if (!(r || cx || cy || n))
			break;
		for (int i = 0; i < n; i++)
			getInput();
		for (int i = 0; i < cnt - 1; i++)
			for (int j = i + 1; j < cnt; j++)
			{
				// cout << "\nhere:" << i << ":" << j << ":" << arr[i].a << '\n';
				tmp += isCrossInC(&arr[i], &arr[j]);
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