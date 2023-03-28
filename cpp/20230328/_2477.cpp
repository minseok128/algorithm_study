#include <iostream>
#include <algorithm>
using namespace std;

int next[] = {0, 4, 3, 1, 2};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int k, a, b, tmp = 0, min_size = 1, h = 0, w = 0;
	int arr[6][2] = {0};
	cin >> k;
	for (int i = 0; i < 6; i++)
	{
		cin >> a >> b;
		arr[i][0] = a;
		arr[i][1] = b;
	}

	for (int i = 0; i < 6; i++)
	{
		int b = i != 0 ? i - 1 : 5;
		int f = i != 5 ? i + 1 : 0;
		// cout << b << "," << f << '\n';
		if (arr[b][0] == arr[f][0])
			min_size *= arr[i][1];
		if (arr[i][0] == 1 || arr[i][0] == 2)
			h = max(h, arr[i][1]);
		else if (arr[i][0] == 3 || arr[i][0] == 4)
			w = max(w, arr[i][1]);
	}
	cout << (w * h - min_size) * k << '\n';
}