#include <string>
#include <vector>

#define MAX 210
#define INF 1e9

using namespace std;

int cost[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    fill(&cost[0][0], &cost[0][0] + MAX * MAX, INF);
    
    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }
    
    for (auto &f : fares) {
        cost[f[0]][f[1]] = f[2];
        cost[f[1]][f[0]] = f[2];
    }
    
    // 플로이드 워셜
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][k] + cost[k][j] < cost[i][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    long long min_cost = INF;
    for (int i = 1; i <= n; i++) {
        if (min_cost > cost[s][i] + cost[i][a] + cost[i][b]) {
            min_cost = cost[s][i] + cost[i][a] + cost[i][b];
        }
    }
    
    return min_cost;
}