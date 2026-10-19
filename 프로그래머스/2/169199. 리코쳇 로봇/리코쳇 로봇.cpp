#include <string>
#include <vector>
#include <memory.h>
#include <queue>

#define MAX 110
using namespace std;

typedef struct {
    int x, y, cnt;
} Node;

int N, M;
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_possible(int x, int y, const vector<string> &board) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    if (board[x][y] == 'D') return false;
    return true;
}

int bfs(int rx, int ry, int gx, int gy, const vector<string> &board) {
    memset(visited, false, sizeof(visited));
    
    queue<Node> q;
    q.push({rx, ry, 0});
    visited[rx][ry] = true;
    
    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        int ccnt = q.front().cnt;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cx;
            int ny = cy;
            while(is_possible(nx, ny, board)) {
                nx += dx[i];
                ny += dy[i];
            }
            nx -= dx[i];
            ny -= dy[i];
            
            if (visited[nx][ny]) continue;
            
            if (gx == nx && gy == ny) {
                return ccnt + 1;
            }            
            
            q.push({nx, ny, ccnt + 1});
            visited[nx][ny] = true;
        }
    }
    return -1;
}

int solution(vector<string> board) {
    
    int rx, ry, gx, gy;
    
    N = board.size();
    M = board[0].size();
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char c = board[i][j];
            if (c == 'G') {
                gx = i;
                gy = j;
            }
            else if (c == 'R') {
                rx = i;
                ry = j;
            }
        }
    }
    
    return bfs(rx, ry, gx, gy, board);
}