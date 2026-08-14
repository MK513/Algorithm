#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <iostream>

#define MAX 55

using namespace std;

typedef pair<int, int> pii;

int N, M;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isPossible(int x, int y, char ch) {
    if (x < 0 || y < 0 || x > N + 1 || y > M + 1) return false;
    if (visited[x][y]) return false;
    if (grid[x][y] == '.' || grid[x][y] == ch) return true;
    return false;
}

void deleteBFS(char ch) {
    queue<pii> q;
    vector<pii> deleted;
    memset(visited, false, sizeof(visited));
    
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        pii cur = q.front();
        int cx = cur.first;
        int cy = cur.second;
        q.pop();
        
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (isPossible(nx, ny, ch)) {
                
                visited[nx][ny] = true;
                
                if (grid[nx][ny] == ch) {
                    deleted.push_back({nx, ny});
                }
                else {
                    q.push({nx, ny});
                }
            }
        }
    }
    
    for (auto [x, y] : deleted) {
        grid[x][y] = '.';
    }
    
}

void deleteAll(char ch) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == ch) {
                grid[i][j] = '.';
            }
        }
    }
}

int countRemain() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] != '.') {
                cnt++;
            }
        }
    }
    return cnt;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;

    N = storage.size();
    M = storage[0].size();
    
    fill(&grid[0][0], &grid[0][0] + MAX * MAX, '.');
    // memset(grid, '.', sizeof(grid));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            grid[i][j] = storage[i - 1][j - 1];
        }
    }
    
    for (string req : requests) {
        if (req.size() == 1) { // 외부 삭제 BFS
            deleteBFS(req[0]);
        }
        else if (req.size() == 2) { // 전부 삭제
            deleteAll(req[0]);
        }
    }
    
    answer = countRemain();
    
    return answer;
}