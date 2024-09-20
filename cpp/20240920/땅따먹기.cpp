#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(vector<int> arr, int index) {
    int max = 0;
    for (int i = 0; i < 4; i++)
        if (arr[i] > max && i != index)
            max = arr[i];
    return max;
}


int solution(vector<vector<int> > land)
{
    int answer = 0, size = land.size();

    for (int i = 1; i < size; i++)
        for (int j = 0; j < 4; j++)
            land[i][j] += getMax(land[i - 1], j); 
    answer = *max_element(land[size - 1].begin(), land[size - 1].end());
    
    return answer;
}