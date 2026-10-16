#include <string>
#include <vector>
#include <memory.h>

#define MAX_N 300100
#define MAX_VAL 2e9

using namespace std;

vector<int> myTeam[MAX_N];
bool is_leaf[MAX_N], visited[MAX_N];
int N;
int leaderOf[MAX_N];
int dp[MAX_N][2]; // cur, 0 : cur이 참석(0,1)여부에 따른 서브트리 최소 매출합

void dfs(int cur, vector<int> &sales) {
    dp[cur][0] = 0;
    dp[cur][1] = sales[cur - 1];
    
    // 리프노드는 바로 종료
    if (myTeam[cur].empty()) return;
    
    int min_diff = 2e9;
    bool is_child_attend = false;
    
    for (int c : myTeam[cur]) {
        dfs(c, sales);
        
        if (dp[c][0] < dp[c][1]) {
            dp[cur][0] += dp[c][0];
            dp[cur][1] += dp[c][0];
            min_diff = min(min_diff, dp[c][1] - dp[c][0]);
        }
        else {
            dp[cur][0] += dp[c][1];
            dp[cur][1] += dp[c][1];
            is_child_attend = true;
        }
    }
    
    if (!is_child_attend) {
        dp[cur][0] += min_diff;
    }
    
}


int solution(vector<int> sales, vector<vector<int>> links) {
    memset(leaderOf, -1, sizeof(leaderOf));
    memset(is_leaf, true, sizeof(is_leaf));
    memset(dp, 0, sizeof(dp));
    
    N = sales.size();
    
    for (int i = 0; i < links.size(); i++) {
        myTeam[links[i][0]].push_back(links[i][1]);
        leaderOf[links[i][1]] = links[i][0];
        is_leaf[links[i][0]] = false;
    }
    
    // 리프 노드의 dp 값 저장
    memset(visited, false, sizeof(visited));
    
    for (int i = 1; i <= N; i++) {
        if (is_leaf[i]) {
            dp[i][1] = sales[i - 1];
            visited[i] = true;
        }
    }
    
    dfs(1, sales);
    
    return min(dp[1][0], dp[1][1]);
}