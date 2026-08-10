#include <string>
#include <vector>

using namespace std;

bool isPossible(long long level, vector<int>& diffs, vector<int>& times, long long& limit) {
    long long cnt = 0;
    
    for (int i = 0; i < diffs.size(); i++) {
        cnt += times[i];
            
        // 퍼즐 수준이 더 높은 경우
        if (diffs[i] > level && i > 0) {
            cnt += (times[i] + times[i - 1]) * (diffs[i] - level);
        }
    }
    
    return cnt <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    long long l, r, mid;
    l = 1;
    r = 1e15;
    
    while (l <= r) {
        mid = (l + r) / 2;
        
        if (isPossible(mid, diffs, times, limit)) {
            r = mid - 1;
            answer = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    return answer;
}