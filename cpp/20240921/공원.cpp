#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    vector<vector<int>> arr(park.size() + 2, vector<int>(park[0].size() + 2, 0));
    int max_size = 0;

    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == "-1")
                arr[i + 1][j + 1] = min(min(arr[i + 1][j], arr[i][j + 1]), arr[i][j]) + 1;
            max_size = max(max_size, arr[i + 1][j + 1]);
        }
    }
    int answer = 0;
    for (auto i : mats) {
        if (i <= max_size)
            answer = max(i, answer);
    }
    return answer == 0 ? -1 : answer;
}