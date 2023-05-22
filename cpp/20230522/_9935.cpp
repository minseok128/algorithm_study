#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string a, b;
	char s[1'000'001];
	cin >> a >> b;
	int a_len = a.length(), b_len = b.length(), j = 0, k;
	for (int i = 0; i < a_len; i++, j++)
	{
		s[j] = a[i];
		if (s[j] == b[b_len - 1] && j - b_len + 1 >= 0)
		{
			for (k = 0; b[k]; k++)
				if (s[j - b_len + 1 + k] != b[k])
					break ;
			if (k == b_len)
				j -= k;
		}
	}
	if (j == 0)
		cout << "FRULA\n";
	else
		for (int i = 0; i < j; i++)
			cout << s[i];
}