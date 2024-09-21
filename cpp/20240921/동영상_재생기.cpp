#include <string>
#include <vector>
#include <iostream>

using namespace std;

int stringTime2int(string time) {
    int h = (time[0] - '0') * 10 + (time[1] - '0');
    int s = (time[3] - '0') * 10 + (time[4] - '0');
    return h * 60 + s;
}

string intTime2String(int time) {
    int h = time / 60;
    string hs = h < 10 ? "0" + to_string(h) : to_string(h);
    int s = time % 60;
    string ss = s < 10 ? "0" + to_string(s) : to_string(s);
    return hs + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int now = stringTime2int(pos);
    int opStart = stringTime2int(op_start);
    int opEnd = stringTime2int(op_end);
    int videoEnd = stringTime2int(video_len);

    now = (opStart <= now && now < opEnd) ? opEnd : now;
    for (auto command : commands) {
        now = command[0] == 'p' ? max(0, now - 10) : min(videoEnd, now + 10);
        now = (opStart <= now && now < opEnd) ? opEnd : now;
    }

    string answer = intTime2String(now);
    return answer;
}