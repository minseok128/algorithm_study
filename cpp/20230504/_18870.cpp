#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int ord[1000000], res[1000000];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		ord[i] = i;
	}
	sort(ord, ord + n, [](int a, int b)
		 { return (arr[a] < arr[b]); });

	res[ord[0]] = 0;
	for (int i = 1; i < n; i++)
	{
		res[ord[i]] = res[ord[i - 1]];
		if (arr[ord[i]] != arr[ord[i - 1]])
			res[ord[i]]++;
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
}