#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int fail[1000001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	vector<int> pos;
	string T, P;
	getline(cin, T);
	getline(cin, P);
	unsigned int P_size = P.length(), T_size = T.length();
	
	if (P_size > T.size())
	{
		cout << "0\n";
		return (0);
	}
	for (int i = 1, j = 0; i < P_size; i++)
	{
		while (j > 0 && P[j] != P[i])
			j = fail[j - 1];
		if (P[i] == P[j])
		{
			j++;
			fail[i] = j;
		}
		else
			fail[i] = 0;
	}
	//for (int k = 0; k < P_size; k++)
	//{
	//	cout << fail[k] << ' ';
	//}
	int j = 0;
	for (int i = 0; i < T_size; i++)
	{
		while (j > 0 && T[i] != P[j])
			j = fail[j - 1];
		//cout << "i:" << i << '\n';
		if (T[i] == P[j])
		{
			if (j == P_size - 1)
			{
				pos.emplace_back(i - P_size + 2);
				j = fail[j];
			}
			else
				j++;

		}
	}
	cout << pos.size() << '\n';
	for (int i = 0; i < pos.size(); i++)
		cout << pos[i] << ' ';
}