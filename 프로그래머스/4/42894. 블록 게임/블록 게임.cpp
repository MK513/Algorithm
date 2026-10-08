#include <string>
#include <vector>

#define MAX 210

using namespace std;

typedef pair<int, int> pii;

int N, block_sz;
vector<pii> blocks[MAX], emptys[MAX];

void get_block_loc(int x, int y, vector<vector<int>>& board) {
    int block = board[x][y];
    int minR = x, maxR = x, minC = y, maxC = y;
    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board.size(); j++)
            if (board[i][j] == block) {
                minR = min(minR, i); maxR = max(maxR, i);
                minC = min(minC, j); maxC = max(maxC, j);
            }
    for (int i = minR; i <= maxR; i++) {
        for (int j = minC; j <= maxC; j++) {
            if (board[i][j] != block) {
                emptys[block].push_back({i, j});
            }
            else {
                blocks[block].push_back({i, j});
            }
        }
    }
    return;
}

bool can_locate_black(int x, int y, vector<vector<int>> &board) {
    for (int i = 0; i <= x; i++)
        if (board[i][y] != 0) return false;
    return true;
}

bool can_erase(int block, vector<vector<int>> &board) {
    
    for (int i = 0; i < 2; i++) {
        int x = emptys[block][i].first;
        int y = emptys[block][i].second;
        
        if (!can_locate_black(x, y, board)) {
            return false;
        }
    }
    return true;
}

void erase(int block, vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) {
        int x = blocks[block][i].first;
        int y = blocks[block][i].second;
        board[x][y] = 0;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    for (int i = 0; i < MAX; i++) {
        blocks[i].clear();
        emptys[i].clear();
    }
    
    N = board.size();
    block_sz = 0;
    vector<bool> visited(MAX, false);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0 && !visited[board[i][j]]) {
                get_block_loc(i, j, board);
                visited[board[i][j]] = true;
                block_sz = max(block_sz, board[i][j]);
            }
        }    
    }
    
    fill(visited.begin(), visited.end(), false);
    
    bool erased = true;
    while (erased) {
        erased = false;
        for (int i = 1; i <= block_sz; i++) {
            
            // 아직 안지웠고, 지울수 있으면
            if (!visited[i] && emptys[i].size() == 2 && can_erase(i, board)) {
                erase(i, board); // 보드에서 지우기
                
                answer++;
                erased = true;
                visited[i] = true;
            }
        }
    }
    
    return answer;
}