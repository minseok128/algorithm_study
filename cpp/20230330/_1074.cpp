#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n, r, c, result = 0;
	cin >> n >> r >> c;
	for (int i = n; i > 0; i--)
	{
		cout << (c / (1 << (i - 1))) << "," << (r / (1 << (i - 1))) << '\n';
		cout << (1 << (2 * (i - 1))) << "," << (1 << ((2 * (i - 1)) + 1)) << "\n\n";
		result += (c / (1 << (i - 1))) ? (1 << (2 * (i - 1))) : 0;
		result += (r / (1 << (i - 1))) ? (1 << ((2 * (i - 1)) + 1)) : 0;
	}
	cout << result << '\n';
}