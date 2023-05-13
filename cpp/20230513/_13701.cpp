#include <iostream>
#include <bitset>
using namespace std;

bitset<33554432> bit;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int tmp;
	while (cin >> tmp)
	{
		if (!bit[tmp])
		{
			cout << tmp << ' ';
			bit.set(tmp, 1);
		}
	}
}