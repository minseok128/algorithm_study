#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<char> arr(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	int m, k, tmp, flag;
	cin >> m >> k;
	for (int i = 0; i < m; i++)
	{
		flag = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> tmp;
			if (arr[tmp] == 'P')
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "W\n";
			return (0);
		}
	}
	cout << "P\n";
}