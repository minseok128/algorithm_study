#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int divA[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int main()
{
	int N, M, div;
	cin >> N >> M;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	div = divA[N - M];
	sort(arr.begin(), arr.end());
	int i = 0;
	do {
		if (i % div == 0)
		{
			for (int j = 0; j < M; j++)
				cout << arr[j] << ' ';
			cout << '\n';
		}
		i++;
	} while (next_permutation(arr.begin(), arr.end()));
}