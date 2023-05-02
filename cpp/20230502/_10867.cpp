#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, tmp;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++)
		cin >> s[i];
	sort(s.begin(), s.end());
	auto end = s.erase(unique(s.begin(), s.end()), s.end());
	for (auto i = s.begin(); i != end; i++)
		cout << *i << ' ';
}