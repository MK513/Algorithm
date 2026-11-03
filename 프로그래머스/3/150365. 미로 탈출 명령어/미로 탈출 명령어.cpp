#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX_N 51
#define MAX_M 51
#define MAX_K 2501

using namespace std;

typedef struct {
    int x, y, cnt;
    string path;
} Node;

bool visited[MAX_N][MAX_M][MAX_K];
char dd[4] = {'d', 'l', 'r', 'u'}; 
int dx[4] = { 1, 0, 0, -1 }; // d l r u
int dy[4] = { 0, -1, 1, 0 };

bool is_possible(int x, int y, int n, int m, int nk) {
    if (x < 1 || y < 1 || x > n || y > m) return false;
    if (visited[x][y][nk]) return false;
    return true;
}

string BFS(int n, int m, int x, int y, int r, int c, int k) {
    queue<Node> q;
    q.push({x, y, 0, ""});
    visited[x][y][0] = true;
    
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (is_possible(nx, ny, n, m, cur.cnt + 1)) {
                
                if (nx == r && ny == c && k == cur.cnt + 1) {
                    return cur.path + dd[i];
                }

                visited[nx][ny][cur.cnt + 1] = true;
                q.push({nx, ny, cur.cnt + 1, cur.path + dd[i]});
            }
        }
    }
    
    return "impossible";
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 != 0) return "impossible";
    
    return BFS(n, m, x, y, r, c, k);
}