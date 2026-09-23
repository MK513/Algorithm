#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_one(string& s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') ret++;
    }
    return ret;
}

string to_binary(int num) {
    string ret = "";
    while (num > 0) {
        ret += to_string(num % 2);
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> solution(string s) {
    
    vector<int> answer;
    
    int cnt = 0;
    int deleted = 0;
    while (s != "1") {
        
        int one_cnt = count_one(s);
        
        deleted += s.size() - one_cnt;
        cnt++;
        
        s = to_binary(one_cnt);
        
        if (cnt > 10) break;
    }
    
    answer.push_back(cnt);
    answer.push_back(deleted);
    
    return answer;
}