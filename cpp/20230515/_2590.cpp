#include <iostream>
using namespace std;

int arr[5];
int res, tmp;

int main()
{
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	cin >> res;

	if (arr[4] > 0)
	{
		res += arr[4];
		tmp = arr[4] * 11 - arr[0];  
		if (tmp >= 0)
			arr[0] = 0;
		else
			arr[0] = tmp * -1;
	}

	if (arr[3] > 0)
	{
		res += arr[3];
		tmp = arr[3] * 5 - arr[1];
		if (tmp >= 0)
		{
			arr[1] = 0;
			tmp = tmp * 4 - arr[0];
			if (tmp >= 0)
				arr[0] = 0;
			else
				arr[0] = tmp * -1;
		}
		else
			arr[1] = tmp * -1;
	}

	if (arr[2] > 0)
	{
		res += (arr[2] % 4) == 0 ? arr[2] / 4 : arr[2] / 4 + 1;
		tmp = arr[2] % 4;
		if (tmp >= 1)
		{
			tmp = (4 - tmp) * 9;
			if (tmp == 9)
			{
				if (arr[1] > 0)
				{
					arr[1]--;
					tmp = 5;
				}
				tmp = tmp - arr[0];
				if (tmp >= 0)
					arr[0] = 0;
				else
					arr[0] = tmp * -1;
			}
			if (tmp == 18)
			{
				if (arr[1] > 2)
				{
					arr[1] -= 3;
					tmp = 6;
				}
				else if (arr[1] > 0)
				{
					tmp -= arr[1] * 4;
					arr[1] = 0;
				}
				tmp = tmp - arr[0];
				if (tmp >= 0)
					arr[0] = 0;
				else
					arr[0] = tmp * -1;
			}
			if (tmp == 27)
			{
				if (arr[1] > 4)
				{
					arr[1] -= 5;
					tmp = 7;
				}
				else if (arr[1] > 0)
				{
					tmp -= arr[1] * 4;
					arr[1] = 0;
				}
				tmp = tmp - arr[0];
				if (tmp >= 0)
					arr[0] = 0;
				else
					arr[0] = tmp * -1;
			}
		}
	}

	if (arr[1] > 0)
	{
		res += (arr[1] % 9) == 0 ? arr[1] / 9 : arr[1] / 9 + 1;
		tmp = arr[1] % 9;
		if (tmp)
		{
			tmp = (9 - tmp) * 4 - arr[0];
			if (tmp >= 0)
				arr[0] = 0;
			else
				arr[0] = tmp * -1;
		}
	}
	
	res += (arr[0] % 36) == 0 ? arr[0] / 36 : arr[0] / 36 + 1;

	cout << res << '\n';
}