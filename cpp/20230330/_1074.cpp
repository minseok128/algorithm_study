#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, r, c, result = 0;
	cin >> n >> c >> r;
	for (int i = n; i > 0; i--)
	{
		result += (r / (1 << (i - 1))) ? (1 << (2 * (i - 1))) : 0;
		result += (c / (1 << (i - 1))) ? (1 << ((2 * (i - 1)) + 1)) : 0;
		r %= (1 << (i - 1));
		c %= (1 << (i - 1));
	}
	cout << result << '\n';
}