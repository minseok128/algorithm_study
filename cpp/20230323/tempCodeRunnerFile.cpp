#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;
	long long H = 0;
	string s;

	cin >> N >> s;
	for (int i = 0; i < N; i++)
	{
		H += (s[0] - 'a' + 1) * pow(31, i);
		H %= 1234567891;
	}
	cout << H << '\n';
}