#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <iostream>


using namespace std;

bool candidates[11];
unordered_set<string> pos;

int toDex(string num, int d) {
    int ret = 0, base = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        ret += base * digit;
        base *= d;
    }
    return ret;
}

string toOther(int num, int d) {
    if (num == 0) return "0";
    
    string ret = "";
    while (num) {
        ret += to_string(num % d);
        num /= d;
    }
    
    reverse(ret.begin(), ret.end());
    
    return ret;
}


string calculate(string expr) {
    stringstream ss(expr);
    string A, op, B, eq, C;
    ss >> A >> op >> B >> eq >> C;
    
    pos.clear();
    
    for (int i = 2; i <= 9; i++) {
        // 후보가 아니면 생략
        if (!candidates[i]) continue;
        
        int result;
        switch(op[0]) {
            case '+' :
                result = toDex(A, i) + toDex(B, i);
                break;
            case '-' :
                result = toDex(A, i) - toDex(B, i);
                break;
        }
        
        // x값 검증
        if (C[0] == 'X') {
            pos.insert(toOther(result, i));
            if (pos.size() >= 2) break;
        }
        // X가 없고 식이 비성립하면 후보에서 제거
        else if (result != toDex(C, i)) {
            candidates[i] = false;
        }
    }
    
    string ret = A + " " + op + " " + B + " " + eq + " ";
    if (pos.size() == 1)  {
        ret += *pos.begin();
    }
    else if (pos.size() >= 1) {
        ret += "?";
    }
    
    return ret;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> uncertain;
    
    // 숫자 확인 후 사전 제외
    int max_num = 0;
    for (string &e : expressions) {
        for (char &ch : e) {
            if (ch == '-' || ch == '+' || ch == '=' || ch == 'X') continue;
            max_num = max(max_num, ch - '0');
        }
    }
    for (int i = max_num + 1; i <= 9; i++) {
        candidates[i] = true;
    }
    
    for (string& e : expressions) {
        if (e.find('X') != string::npos) {
            uncertain.push_back(e);
        }
        else {
            calculate(e);
        }
    }
    
    for (string& u : uncertain) {
        answer.push_back(calculate(u));
    }
    
    return answer;
}