#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int E9 = 1e9;

typedef struct
{
	long long x, y;
	int idx;
} Point;

int N;
Point sp;
vector<Point> arr;

int compare(Point a, Point b)
{
	long long ar, br;
	ar = atan2(a.y - sp.y, a.x - sp.x) * E9;
	br = atan2(b.y - sp.y, b.x - sp.x) * E9;
	if (a.x == sp.x && a.y == sp.y)
		return (1);
	if (b.x == sp.x && b.y == sp.y)
		return (0);
	if (ar == br)
	{
		if (a.x == sp.x)
			return (a.y < b.y);
		return (a.x < b.x);
	}
	return (ar < br);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int T;
	for (cin >> T; T > 0; T--)
	{
		sp.y = 1000000000;
		sp.x = 1000000000;
		arr.clear();

		cin >> N;
		Point np;
		for (int i = 0; i < N; i++)
		{
			cin >> np.x >> np.y;
			np.idx = i;
			arr.emplace_back(np);
			if (np.x < sp.x || (np.x == sp.x && np.y < sp.y))
				sp = np;
		}
		sort(arr.begin(), arr.end(), compare);
		long long ar, br;
		ar = atan2(arr[N - 1].y - sp.y, arr[N - 1].x - sp.x) * E9;
		br = atan2(arr[N - 2].y - sp.y, arr[N - 2].x - sp.x) * E9;
		if (ar == br)
		{
			int j = -1;
			while (ar == br && N + j != 0)
			{
				ar = atan2(arr[N + j].y - sp.y, arr[N + j].x - sp.x) * E9;
				br = atan2(arr[N + j - 1].y - sp.y, arr[N + j - 1].x - sp.x) * E9;
				j--;
			}
			j++;
			// cout << "j:" << j << '\n';
			reverse(arr.end() + j, arr.end());
		}

		int flag = 0, flag2 = 1;
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i].idx << ' ';
		}
		cout << '\n';
	}
}