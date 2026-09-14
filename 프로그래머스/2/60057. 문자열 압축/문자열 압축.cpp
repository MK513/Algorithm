#include <string>
#include <vector>

using namespace std;

int N;

int count_str(string& s, int len) {
    int ret = 0;
    int i, cnt = 1;
    
    string cur = s.substr(0, len);
    for (i = len; i < N; i += len) {
        // 이전 문자열과 동일함
        if (cur == s.substr(i, len)) {
            cnt++;
        }
        // 이전 문자열과 다름
        else {
            cur = s.substr(i, len);
            ret += len;
            
            
            // 1개 초과면 숫자 개수 카운팅
            if (cnt != 1) {
                ret += to_string(cnt).size();
            }
            
            cnt = 1;
        }
    }
    
    // 딱 등분되서 끝나지 않은 경우 처리
    if (i > N) {
        ret += N - (i - len);
    }
    // i == N 으로 끝났을 때
    else {
        ret += len;
        if (cnt != 1) {
            ret += to_string(cnt).size();
        }
    }
    
    return ret;
}

int solution(string s) {
    int answer = 1e9;
    N = s.size();
    
    if (s.size() == 1) {
        return 1;
    }
    
    for (int i = 1; i < N / 2 + 1; i++) {
        int cur = count_str(s, i);
        answer = min(cur, answer);
    }
    
    return answer;
}