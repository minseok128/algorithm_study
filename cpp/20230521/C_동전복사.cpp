#include <iostream>
using namespace std;

int main()
{
	int n, x, y, res = 4;
	cin >> n >> x >> y;
	if (x == 1 || x == n) res--;
	if (y == 1 || y == n) res--;
	cout << (n == 1 ? 0 : res);
}
