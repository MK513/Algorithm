#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

unordered_map<string, int> get_elements(string str) {
    unordered_map<string, int> cnt;
    
    for (int i = 0; i < str.size() - 1; i++) {
        string p = str.substr(i, 2);
        
        p[0] = tolower(p[0]);
        p[1] = tolower(p[1]);
        
        if (isalpha(p[0]) && isalpha(p[1])) cnt[p]++;
    }
    
    return cnt;
}


int solution(string str1, string str2) {
        
    unordered_map<string, int> cnt1 = get_elements(str1);
    unordered_map<string, int> cnt2 = get_elements(str2);
    
    if (cnt1.empty() && cnt2.empty()) {
        return 65536;
    }
    
    int sum_set = 0, diff_set = 0;
    for (auto &psi : cnt1) {
        string val = psi.first;
        int c = psi.second;
        
        sum_set += max(c, cnt2[val]);
        diff_set += min(c, cnt2[val]);
    }
    
    for (auto &psi : cnt2) {
        string val = psi.first;
        int c = psi.second;
        
        if (cnt1.find(val) == cnt1.end()) {
            sum_set += c;
        }
    }
    
    int answer =  diff_set * 65536 / sum_set;
    return answer;
}