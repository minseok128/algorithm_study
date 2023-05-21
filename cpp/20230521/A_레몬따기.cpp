#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int tmp, res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		res = max(res, tmp - (n - i + 1 / 2));
	}
	cout << res;
}