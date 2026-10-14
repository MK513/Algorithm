#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

map<int, int> mapper; // num : order

vector<string> split(string &s, char delim) {
    stringstream ss(s);
    string tmp;
    vector<string> ret;
    while(getline(ss, tmp, delim)) ret.push_back(tmp);
    return ret;
}

bool comp(const pii &a, const pii &b) {
    return a.second < b.second;
}

vector<int> solution(string s) {
    
    vector<string> nums;
    string sstack;
    
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') continue;
        else if (s[i] == '}') {
            i++; // , 넘어가기
            
            nums = split(sstack, ',');
            sstack = "";
            
            for (string &i : nums) {
                if (mapper.count(stoi(i))) {
                    mapper[stoi(i)] = min(mapper[stoi(i)], (int)nums.size());
                }
                else {
                    mapper[stoi(i)] = nums.size();
                }
            }
        }
        else {
            sstack += s[i];
        }
    }
    
    vector<pii> pairs;
    for (const auto &p : mapper) {
        pairs.push_back(p);
    }
    
    sort(pairs.begin(), pairs.end(), comp);
    
    vector<int> answer;
    for (const auto &p : pairs) {
        answer.push_back(p.first);
    }

    return answer;
}