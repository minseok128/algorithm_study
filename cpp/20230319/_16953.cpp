#include <iostream>
#include <queue>
using namespace std;

int main()
{
	long long A, B;
	cin >> A >> B;
	queue<pair<long long, long long>> q;

	q.push(make_pair(A, 1));
	while (!q.empty())
	{
		pair<long long, long long> crr = q.front();
		q.pop();

		if (crr.first == B)
		{
			cout << crr.second << '\n';
			return (0);
		}
		if (crr.first < B)
		{
			q.push(make_pair(crr.first * 2, crr.second + 1));
			q.push(make_pair(crr.first * 10 + 1, crr.second + 1));
		}
	}
	cout << "-1" << '\n';
	return (0);
}