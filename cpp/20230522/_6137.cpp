#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int i, j, k = 0;
	cin >> j;
	vector<char> str(j), res(j);
	for (i = 0; i < j; i++)
		cin >> str[i];
	i = 0;
	j--;
	while (i <= j)
	{
		if (str[i] > str[j])
			res[k] = str[j--];
		else if (str[i] == str[j])
		{
			int l = 0;
			while (str[i + l] == str[j - l] && i + l != j - l)
				l++;
			if (str[i + l] > str[j - l])
				res[k] = str[j--];
			else
				res[k] = str[i++];
		}
		else
			res[k] = str[i++];
		k++;
	}
	for (i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i % 80 == 79)
			cout << '\n';
	}
}