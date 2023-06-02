#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	for (cin.ignore(); n > 0; n--)
	{
		string str;
		getline(cin, str);

		int s = 0, e;
		for (int i = 0; i <= str.length(); i++)
		{
			if (str[i] == ' ' || !str[i])
			{
				e = i - 1;
				for (int j = e; j >= s; j--)
					cout << str[j];
				cout << ' ';
				s = e + 2;
			}
		}
		cout << '\n';
	}
}