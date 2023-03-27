#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int uc = 0, dp = 0, flag = 1;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U' || s[i] == 'C')
			uc++;
		else if (s[i] == 'D' || s[i] == 'P')
			dp++;
	}
	if (dp % 2 == 1)
		dp++;
	if (uc > dp / 2)
	{
		flag = 1;		
		cout << "U";
	}
	if (dp > 0)
	{
		cout << "DP";
		flag = 1;
	}
	if (flag == 0)
		cout << "C";
	
}