#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> term;

vector<string> split(string &s, char delim) {
    vector<string> ret;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, delim)) ret.push_back(tmp);
    return ret;
}

string get_end_date(string &privacy) {
    vector<string> tmp = split(privacy, ' ');
    string from = tmp[0];
    int valid_month = term[tmp[1]];
    
    tmp = split(from, '.');
    int year = stoi(tmp[0]);
    int month = stoi(tmp[1]) + valid_month;
    int day = stoi(tmp[2]) - 1;
    
    if (day == 0) {
        day = 28;
        month -= 1;
    }
    
    if (month > 12) {
        year += month % 12 != 0 ? month / 12 : month / 12 - 1;
        month = month % 12 != 0 ? month % 12 : 12;
    }
    
    return to_string(year) + "." + ((month < 10) ? "0" : "") + to_string(month) + "." + ((day < 10) ? "0" : "") + to_string(day);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    
    for (string &t : terms) {
        vector<string> tmp = split(t, ' ');
        term[tmp[0]] = stoi(tmp[1]);
    }
    
    
    vector<int> answer;
    for (int i = 0; i < privacies.size(); i++) {
        
        string end_date = get_end_date(privacies[i]);
        
        if (today > end_date) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}