#include <string>
#include <vector>

#define MAX 1000100
#define INF 1e9

using namespace std;

int dp[MAX];

int solution(int x, int y, int n) {
    fill(dp, dp + MAX , INF);
    
    dp[x] = 0;
    for (int i = x + 1; i <= y; i++) {
        if (i % 2 == 0 && dp[i / 2] != INF) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0 && dp[i / 3] != INF) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i - n > 0 && dp[i - n] != INF) {
            dp[i] = min(dp[i], dp[i - n] + 1);
        }
    }
    
    return dp[y] == INF ? -1 : dp[y];
}