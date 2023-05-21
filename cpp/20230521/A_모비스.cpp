#include <iostream>
using namespace std;

char arr[26];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string str, ans = "MOBIS";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
		arr[str[i]] = 1;
	
	int res = 1;
	for (int i = 0; i < 5; i++)
		res *= arr[ans[i]];
	cout << (res ? "YES" : "NO");
}