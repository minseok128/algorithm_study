#include <iostream>
#include <bitset>
using namespace std;

int N, res = 100002;
bitset<100001> origin, target;

int solve()
{
	int cnt = 0;
	bitset<100001> bit(origin);
	for (int i = 1; i < N; i++)
	{
		if (bit[i - 1] ^ target[i - 1])
		{
			bit.flip(i - 1);
			bit.flip(i);
			if (i != N - 1)
				bit.flip(i + 1);
			cnt++;
		}
	}
	return ((target ^ bit).any() ? -1 : cnt);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string str;
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
		origin.set(i, str[i] - '0');
	cin >> str;
	for (int i = 0; i < N; i++)
		target.set(i, str[i] - '0');

	int tmp = solve();
	if (tmp != -1)
		res = solve();
	origin.flip(0);
	origin.flip(1);
	tmp = solve() + 1;
	if (tmp)
		res = res > tmp ? tmp : res;
	cout << (res == 100002 ? -1 : res) << '\n';
}