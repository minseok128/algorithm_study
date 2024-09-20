#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare1(const pair<float, int>& a, const pair<float, int>& b) {
    if (a.first > b.first)
        return true;
    if (a.first == b.first)
        return a.second < b.second;
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> arr(N + 2, 0), sumArr(N + 2, 0);
    
    for (int i = 0; i < stages.size(); i++)
        arr[stages[i]]++;
    sumArr[N + 1] = arr[N + 1];
    for (int i = N; i > 0; i--)
        sumArr[i] = sumArr[i + 1] + arr[i];
    
    vector<pair<float, int>> result(N);
    for (int i = 0; i < N; i++)
    {
        if (sumArr[i + 1] == 0)
            result[i].first = 0;
        else
            result[i].first = arr[i + 1] / (float)sumArr[i + 1];
        result[i].second = i;
        // cout << result[i].first << " | " << result[i].second << '\n';
    }
    
    vector<int> answer;
    sort(result.begin(), result.end(), compare1);
    for (int i = 0; i < N; i++)
        // cout << result[i].second + 1 << ' ';
        answer.push_back(result[i].second + 1);
    
    return answer;
}