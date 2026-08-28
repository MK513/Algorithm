#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

int getTime(string t) {
    string h = t.substr(0, 2);
    string m = t.substr(3, 2);
    return stoi(h) * 60 + stoi(m);
}

bool comp(vector<string> &a, vector<string> &b) {
    return getTime(a[1]) < getTime(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), comp);
    
    int cur_time = getTime(plans[0][1]);
    stack<string> stk;
    unordered_map<string, int> remain_time;
    for (vector<string> &p : plans) {
        
        int start_time = getTime(p[1]);
        
        while(!stk.empty()) {
            if (cur_time + remain_time[stk.top()] <= start_time) {
                cur_time += remain_time[stk.top()];
                answer.push_back(stk.top());
                stk.pop();
            }
            else {
                remain_time[stk.top()] -= (start_time - cur_time);
                cur_time = start_time;
                break;
            }
        }
        
        cur_time = start_time;
        stk.push(p[0]);
        remain_time[p[0]] = stoi(p[2]);
    }
    
    while(!stk.empty()) {
        answer.push_back(stk.top());
        stk.pop();
    }
    
    return answer;
}