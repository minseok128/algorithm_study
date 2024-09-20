#include <string>
#include <vector>
#include <iostream>

using namespace std;

int char2index(char c) {
    if (c == 'R')
        return 0;
    if (c == 'T')
        return 1;
    if (c == 'C')
        return 2;
    if (c == 'F')
        return 3;
    if (c == 'J')
        return 4;
    if (c == 'M')
        return 5;
    if (c == 'A')
        return 6;
    return 7;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> score(8, 0);
    

    
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] > 4)
            score[char2index(survey[i][0])] += 4 - choices[i];
        else if (choices[i] < 4)
            score[char2index(survey[i][1])] += choices[i] - 4;
    }
    
    if (score[0] >= score[1])
        answer += "R";
    else
        answer += "T";
    
    if (score[2] >= score[3])
        answer += "C";
    else
        answer += "F";
    
    if (score[4] >= score[5])
        answer += "J";
    else
        answer += "M";
    
    if (score[6] >= score[7])
        answer += "A";
    else
        answer += "N";

    return answer;
}