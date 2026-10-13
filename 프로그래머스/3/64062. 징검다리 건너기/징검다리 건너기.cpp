#include <string>
#include <vector>
#include <deque>

#define MAX 2 * 1e8

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = MAX;
    deque<int> dq;
    
    for (int i = 0; i < stones.size(); i++) {
        
        while (!dq.empty() && stones[dq.back()] <= stones[i]) dq.pop_back();
        
        dq.push_back(i);
        
        if (dq.front() <= i - k) dq.pop_front();
        
        if (i >= k - 1) answer = min(answer, stones[dq.front()]);
    }
    
    return answer;
}