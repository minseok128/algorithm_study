#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	string s, rs;
	while (1)
	{
		cin >> s;
		if (s.compare("0") == 0)
			break;
		rs = s;
		reverse(rs.begin(), rs.end());
		s[s.length() / 2] = rs[s.length() / 2] = 0;
		if (s.compare(rs))
			cout << "no\n";
		else
			cout << "yes\n";
	}
}