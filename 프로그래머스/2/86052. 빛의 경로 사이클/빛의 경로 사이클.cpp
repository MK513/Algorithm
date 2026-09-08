#include <string>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, M;
bool visited[510][510][4]; // 상 좌 하 우
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int count_cycle(int x, int y, int dir, vector<string> &grid) {
    int ret = 0;
    while(!visited[x][y][dir]) {
        visited[x][y][dir] = true;
        
        x = (x + dx[dir] + N) % N;
        y = (y + dy[dir] + M) % M;
        
        if (grid[x][y] == 'L') {
            dir = (dir + 1) % 4;
        }
        else if (grid[x][y] == 'R') {
            dir = (dir + 3) % 4;
        }
        ret++;
    }
        
    return ret;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    memset(visited, sizeof(visited), false);
    N = grid.size();
    M = grid[0].size();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                if (visited[i][j][k]) continue;
                
                int cycle = count_cycle(i, j, k, grid);
                answer.push_back(cycle);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}