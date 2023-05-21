#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long N, M, X, base;
long long arr[100'000];

long long solve(long long s, long long e, long long idx, long long left) 
{
    long long m;
    while(e-s > 0)
     {
        m = (s+e)/2;
        if (X - (m * arr[idx]) > base * (left - m)) s=m+1;
        else e = m;
    }
    return e+1;
}

long long upperBound(long long s, long long e, long long idx, long long left) {
	long long low = s;
	long long high = e;
	while (low < high) {
		long long m = low + (high - low)/2;
		if (X - (m * arr[idx]) == base * (left - m)) return (m);
		if (X - (m * arr[idx]) < base * (left - m)) {
			high = m;
		} else {
			low = m + 1;
		}
	}
	cout << idx << ":";
	cout << X - (low * arr[idx]) << ' ' << base * (left - low) << ' ' << left - low << '\n'; 
	return low;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
		cin >> arr[i];
	
	base = arr[M - 1];
	long long tmp;
	for (int i = 0; i < M - 1; i++)
	{
		tmp = upperBound(0, N, i, N);
		cout << tmp << ' ' << X << '\n';
		X -= arr[i] * tmp;
		N -= tmp;
	}
	cout << X / base;
}