#include <iostream>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string S, P;
	cin >> S >> P;

	int res = 0, tmp = 0;
	for (int i = 0; P[i];)
	{
		for (int j = 0; S[j]; j++)
		{
			int k = 0;
			while (S[j + k] && S[j + k] == P[i + k])
				k++;
			if (k > tmp)
				tmp = k;
		}
		res++;
		i += tmp;
		tmp = 0;
	}
	cout << res << '\n';
}