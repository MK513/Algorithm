#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

int K, N, answer;
int consultants[6];
vector<pii> requests[6];

int calculate_each(int idx) {
    int ret = 0;
    int tmp[6];
    priority_queue<int, vector<int>, greater<int>> finish_time;
    copy(consultants, consultants + 6, tmp);
    
    for (auto [st, due_time] : requests[idx]) {
        
        // 현재 시간 체크해서 끝난 상담 큐에서 제거
        while (!finish_time.empty() && finish_time.top() <= st) {
            finish_time.pop();
            tmp[idx]++;
        }
        
        int finished_at;
        // 빈 상담사 있으면 바로 할당
        if (tmp[idx] > 0) {
            tmp[idx]--;
            finished_at = st + due_time;
        }
        // 없으면 대기 시간 계산
        else {
            if (finish_time.empty()) continue;
            ret += finish_time.top() - st;
            finished_at = finish_time.top() + due_time;
            finish_time.pop();
        }
        finish_time.push(finished_at);
    }
    return ret;
}

int calculate() {
    int ret = 0;
    for (int i = 1; i <= K; i++) {
        ret += calculate_each(i);
    }
    
    return ret;
}

void backtrack(int idx, int n) {
    if (idx <= K && n == 0) return;
    
    if (idx == K + 1) {
        // 남은 시간 계산 후 최솟값 구하기
        if (n == 0) {
            answer = min(answer, calculate());
        }
        return;
    }
    
    
    for (int i = 1; i <= n; i++) {
        consultants[idx] += i;
        backtrack(idx + 1, n - i); 
        consultants[idx] -= i;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    K = k;
    N = n;
    
    memset(consultants, 0, sizeof(consultants));
    
    // reqs 유형 별로 저장
    for (auto r : reqs) {
        requests[r[2]].push_back({r[0], r[1]});
    }
    
    // 유형별 상담사 backtrack으로 완전 탐색
    answer = 1e9;
    backtrack(1, N);
    
    return answer;
}