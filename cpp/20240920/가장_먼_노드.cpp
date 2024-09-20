#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<short>> graph(n + 1);
    
    for (int i = 0; i < edge.size(); i++)
    {
        graph[edge[i][0]].push_back((short)edge[i][1]);
        graph[edge[i][1]].push_back((short)edge[i][0]);
    }
    
    vector<int> isVisited(n + 1, 0);
    isVisited[1] = 1;
    queue<int> q;
    q.push(1);
        
    int answer = 0, maxDist = 0; 
    while (!q.empty())
    {
        int next = q.front();
        // cout << next << ' ';
        q.pop();
        
        for (int i = 0; i < graph[next].size(); i++)
        {
            int j = graph[next][i];
            if (isVisited[j] == 0)
            {
                q.push(j);
                isVisited[j] = isVisited[next] + 1;
                if (isVisited[j] > maxDist)
                {
                    answer = 0;
                    maxDist = isVisited[j];
                }
                answer++;
            }   
        }
    }
    
    
    return answer;
}