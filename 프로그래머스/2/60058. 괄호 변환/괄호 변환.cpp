#include <string>
#include <vector>
#include <stack>

using namespace std;

string dfs(const string &u) {
    if (u == "") return "";
    
    stack<char> stk;
    int lcnt = 0, rcnt = 0, idx = 0;
    bool isCorrect = true;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(') {
            lcnt++;
            stk.push('(');
        }
        else if (u[i] == ')') {
            rcnt++;
            if (!stk.empty()) stk.pop();
            else isCorrect = false;
        }
        
        if (lcnt == rcnt) {
            idx = i + 1;
            break;
        }
    }
    
    string uu = u.substr(0, idx);
    string vv = u.substr(idx);
    
    if (isCorrect && stk.empty()) {
        return uu + dfs(vv);
    }
    
    string tmp = "";
    for (int i = 1; i < uu.size() - 1; i++) {
        if (uu[i] == ')') tmp += '(';
        else if (uu[i] == '(') tmp += ')';
    }
    
     return "(" + dfs(vv) + ")" + tmp;
}

string solution(string p) {
    return dfs(p);
}