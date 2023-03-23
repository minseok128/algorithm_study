#include <iostream>
#include <string>
using namespace std;

long long pow_31(int i)
{
	long long r = 1;
	for (int j = 0; j < i; j++)
	{
		r *= 31;
		r %= 1234567891;
	}
	return (r);
}

int main()
{
	int N;
	long long H = 0;
	string s;

	cin >> N >> s;
	for (int i = 0; i < N; i++)
	{
		H += (s[i] - 'a' + 1) * (pow_31(i));
		H %= 1234567891;
	}
	cout << H << '\n';
}