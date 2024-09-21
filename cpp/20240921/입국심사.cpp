#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

ll solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    ll low = 0, high = times.back() * n, mid;

    while (low != high) {
        mid = (low + high) / 2;
        ll comp_n = 0;
        for (auto i : times)
            comp_n += mid / i;
        if (comp_n >= n)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}