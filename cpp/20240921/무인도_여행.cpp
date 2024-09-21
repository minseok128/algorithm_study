#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] == 'X')
                continue;
            int result = 0;
            queue<pair<int, int>> q;
            q.push({i, j});
            result += maps[i][j] - '0';
            maps[i][j] = 'X';
            while(!q.empty()) {
                pair<int, int> next = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    pair<int, int> newNext = {next.first + dy[j], next.second + dx[j]};
                    if (newNext.first < 0 || newNext.first >= maps.size()
                        || newNext.second < 0 || newNext.second >= maps[0].size())
                        continue;
                    if (maps[newNext.first][newNext.second] != 'X') {
                        q.push(newNext);
                        result += maps[newNext.first][newNext.second] - '0';
                        maps[newNext.first][newNext.second] = 'X';
                    }
                }
            }
            answer.push_back(result);
        }
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    return answer;
}