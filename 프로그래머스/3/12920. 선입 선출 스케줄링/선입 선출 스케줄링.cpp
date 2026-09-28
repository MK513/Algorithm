#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N, answer;

bool is_possible(int num, vector<int> &cores) {
    int csum = 0;
    for (int i = 0; i < cores.size(); i++) {
        csum += num / cores[i];
        if (csum >= N)  return true;
    }
    return false;
}

int solution(int n, vector<int> cores) {
    
    // 코어가 일 개수 보다 많을때
    if (n <= cores.size()) {
        return n;
    }
    
    answer = -1;
    N = n - cores.size();
    
    // 시간 내에 작업량 충족되는 최소 시간 이분탐색으로 찾기
    int low = 1, high = n * 10000, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (is_possible(mid, cores)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    int target_time = low;
    
    // target_time - 1 대상 시간 1초 전까지 처리된 일의 수 카운팅
    int remain_work = N;
    for (int i = 0; i < cores.size(); i++) {
        remain_work -= (target_time - 1) / cores[i];
    }
    
    // target_time 시간에 마지막 일처리한 코어 확인
    for (int i = 0; i < cores.size(); i++) {
        if(target_time % cores[i] == 0) {
            answer = i + 1;
            remain_work--;
            
            if (remain_work == 0) break;
        }
    }
    
    return answer;
}