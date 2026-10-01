#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int limit, vector<int> &rocks, int n) {
    int cnt = 0;
    int dis = 0;
    for (int i = 1; i < rocks.size(); i++) {
        dis += (rocks[i] - rocks[i - 1]);
        
        if (dis < limit) {
            cnt++;
        }
        else {
            dis = 0;
        }
    }
    return cnt <= n;
}

int solution(int distance, vector<int> rocks, int n) {
    
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    
    int answer = 0;
    int l = 0, r = distance, mid;
    
    while (l <= r) {
        mid = (l + r) / 2;
        
        if (check(mid, rocks, n)) {
            answer = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return answer;
}