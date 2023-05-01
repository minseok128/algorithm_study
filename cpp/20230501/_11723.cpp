#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int set = 0, M ,c;
	string str;
	for (cin >> M; M > 0; M--)
	{
		cin >> str;
		if (str[1] == 'd')
		{
			cin >> c;
			set |= (1 << c);
		}
		else if (str[0] == 'r')
		{
			cin >> c;
			set &= ~(1 << c);
		}
		else if (str[0] == 'c')
		{
			cin >> c;
			cout << ((set & (1 << c)) ? 1 : 0) << '\n';
		}
		else if (str[0] == 't')
		{
			cin >> c;
			set ^= (1 << c);
		}
		else if (str[1] == 'l')
			set = (1 << 31) - 1;
		else if (str[0] == 'e')
			set = 0;
	}
}