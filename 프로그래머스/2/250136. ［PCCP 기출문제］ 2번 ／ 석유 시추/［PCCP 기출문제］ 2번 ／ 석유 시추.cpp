#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>

#define MAX 510

using namespace std;

typedef pair<int, int> pii;

int N, M;
int visited[MAX][MAX];
int poolCnt;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isPossible(int x, int y, vector<vector<int>> &land) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    if (land[x][y] == 0) return false;
    if (visited[x][y]) return false;
    return true;
}

void masking(int x, int y, vector<vector<int>> &land) {
    
    visited[x][y] = poolCnt;
    queue<pii> q;
    vector<pii> v;
    int cnt = 0;
    
    q.push({x,y});
    v.push_back({x, y});
    cnt++;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int cx = cur.first;
        int cy = cur.second;
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (isPossible(nx, ny, land)) {
                cnt++;
                visited[nx][ny] = poolCnt;
                v.push_back({nx, ny});
                q.push({nx, ny});
            }
        }
    }
    
    for (auto [a, b] : v) {
        land[a][b] = cnt;
    }
    return;    
}

int solution(vector<vector<int>> land) {
    memset(visited, 0, sizeof(visited));
    
    N = land.size();
    M = land[0].size();
    
    // 마스킹 bfs
    poolCnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (land[i][j] == 1) {
                poolCnt++;
                masking(i, j, land);
            }
        }
    }
    
    // 순회하면서 계산
    int answer = 0;
    for (int j = 0; j < M; j++) {
    
        set<int> s;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            
            if (visited[i][j] == 0) continue;
            if (s.count(visited[i][j])) continue;
            
            s.insert(visited[i][j]);
            cnt += land[i][j];
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}