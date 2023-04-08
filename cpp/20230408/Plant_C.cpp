#include <iostream>
#include <cmath>
using namespace std;

int samp[11][2];
int numArr[11] = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
int result[2049];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int tmp, sum;

	for (int i = 0; i < 11; i++)
		cin >> samp[i][0];
	result[0] = 1;
	for (int i = 0; i < 2046; i++)
	{
		sum = 0;
		for (int j = 0; j < 11; j++)
		{
			cin >> tmp;
			if (samp[j][0] != tmp)
			{
				sum += numArr[j];
				samp[j][1] = tmp;
			}
		}
		result[sum] = 1;
	}
	for (int i = 0; i < 11; i++)
		cout << samp[i][0] << ' ';
	cout << '\n';
	for (int i = 0; i < 2048; i++)
	{
		if (result[i] == 0)
		{
			for (int j = 10; j >= 0; j--)
			{
				//cout << i << ':' << i / numArr[10 - j] << '|';
				if (i / numArr[10 - j] > 0)
					cout << samp[10 - j][1];
				else
					cout << samp[10 - j][0];
				if (j != 0)
					cout << ' ';
				i %= numArr[10 - j];
			}
			return (0);
		}
	}
}