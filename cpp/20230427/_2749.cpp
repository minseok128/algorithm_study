#include <iostream>
using namespace std;

int arr[1500000];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	long long N;
	cin >> N;

	arr[1] = 1;
	for (int i = 2; i < 1500000; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 1000000;
	}
	cout << arr[N % 1500000] << '\n';
}
