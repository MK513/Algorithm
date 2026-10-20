#include <string>
#include <vector>

typedef long long ll;

using namespace std;

int N;

int solution(vector<int> queue1, vector<int> queue2) {
    
    N = queue1.size();
        
    ll csum = 0, tsum = 0;
    for (int q1 : queue1) {
        tsum += q1;
    }
    csum = tsum;
    
    for (int q2 : queue2) {
        tsum += q2;
        queue1.push_back(q2);
    }

    if (tsum % 2 == 1) return -1;
    if (csum == tsum / 2) return 0;
    
    ll target = tsum / 2;
    
    int l = 0, r = N, cnt = 0;
    int max_ops = 4 * N;
    
    while (cnt <= max_ops && l <= r && r < queue1.size()) {
        if (csum == target) {
            return cnt;
        }
        
        if (csum > target) {
            csum -= queue1[l++];
        }
        else {
            csum += queue1[r++];
        }
        cnt++;
    }
    
    
    return -1;
}