#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, K, pop_count = 0, top = -1;
	string str;

	cin >> N >> K >> str;
	vector<char> s(N);
	for (int i = 0; i < N; i++)
	{
		while (top != -1 && pop_count < K && s[top] < str[i])
		{
			top--;
			pop_count++;
		}
		s[++top] = str[i];
	}
	for (int i = 0; i < N - K; i++)
		cout << s[i];
}