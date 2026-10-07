#include <string>
#include <vector>
#include <memory.h>
#include <queue>

#define MAX 330

using namespace std;

typedef pair<int, int> pii;

typedef struct {
    int x, y, cost;
} Node;

struct Comp {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

bool visited[MAX][MAX];
int N;
int dx[4] = { -1, 0, 1, 0}; // 북 동 남 서
int dy[4] = { 0, 1, 0, -1};

bool is_possible(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    if (visited[x][y]) return false;
    return true;
}

int get_height_diff(int x, int y, int nx, int ny, vector<vector<int>> &land) {
    return abs(land[x][y] - land[nx][ny]);
}

int solution(vector<vector<int>> land, int height) {
    
    memset(visited, false, sizeof(visited));
    N = land.size();
    
    int answer = 0;
    priority_queue<Node, vector<Node>, Comp> pq;
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    int vcnt = 1;
    
    while (1) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (is_possible(nx, ny)) {
                
                int diff = get_height_diff(x, y, nx, ny, land);
                
                if (diff <= height) {
                    vcnt++;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
                else {
                    pq.push({nx, ny, diff});
                }
            }
        }
        
        if (vcnt >= N * N) break;
        
        if (q.empty()) {
            
            int nx = pq.top().x;
            int ny = pq.top().y;
            
            while (!pq.empty() && visited[nx][ny]) {
                pq.pop();
                nx = pq.top().x;
                ny = pq.top().y;
            }
            
            answer += pq.top().cost;
            
            q.push({nx, ny});
            pq.pop();
            
            vcnt++;
            visited[nx][ny] = true;
        }
    }
    
    return answer;
}