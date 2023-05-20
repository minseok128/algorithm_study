#include <iostream>
using namespace std;

int main()
{
	int n, res = 0, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		res += tmp;
	}

	res += (n - 1) * 8;
	cout << res / 24 << ' ' << res % 24;
}