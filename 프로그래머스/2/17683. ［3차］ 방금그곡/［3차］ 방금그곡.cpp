#include <string>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

string processing(string m) {
    vector<pair<string, string>> rep = {
        {"C#", "c"}, {"D#", "d"}, {"F#", "f"},
        {"G#", "g"}, {"A#", "a"}, {"B#", "b"}
    };
    
    for (auto& [from, to] : rep) {
        size_t pos = 0;
        while ((pos = m.find(from, pos)) != string::npos) {
            m.replace(pos, from.size(), to);
            pos += to.size();
        }
    }
    return m;
}

vector<string> split(string &s, char delim) {
    stringstream ss(s);
    string tmp;
    vector<string> ret;
    while (getline(ss, tmp, delim)) ret.push_back(tmp);
    return ret;
}

int toMinute(string times) {
    vector<string> tm = split(times, ':');
    return stoi(tm[0]) * 60 + stoi(tm[1]);
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int topT = 0;
    
    m = processing(m);
    
    for (string &line : musicinfos) {
        vector<string> infos = split(line, ',');
        
        int t = toMinute(infos[1]) - toMinute(infos[0]);
        string musics = "";
        string given = processing(infos[3]);
        
        for (int i = 0; i < t; i++) {
            musics += given[i % given.size()];
        }
        
        if (musics.find(m) != string::npos && topT < t) {
            topT = t;
            answer = infos[2];
        }
    }
    
    return answer;
}