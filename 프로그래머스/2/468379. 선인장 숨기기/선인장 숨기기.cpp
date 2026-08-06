#include <string>
#include <vector>

using namespace std;

int M, N, H, W;

int get_idx(int r, int c) {
    return r * (N + 2) + c;
}

bool check(int mid, const vector<vector<int>> &drops, vector<int> &best_pos) {
    vector<int> grid((M + 2) * (N + 2), 0);
    vector<int> diff((M + 2) * (N + 2), 0);
    
    // mid - 1 번째 까지 마킹
    for (int i = 0; i < mid; i++) {
        int r = drops[i][0];
        int c = drops[i][1];
        
        int ur = max(0, r - H + 1);
        int uc = max(0, c - W + 1);
        int dr = r;
        int dc = c;
        
        diff[get_idx(ur, uc)] += 1;
        diff[get_idx(ur, dc + 1)] -= 1;
        diff[get_idx(dr + 1, uc)] -= 1;
        diff[get_idx(dr + 1, dc + 1)] += 1;
    }
    
    // 누적합 계산
    bool found = false;
    for (int r = 0; r <= M - H; r++) {
        for (int c = 0; c <= N - W; c++) {
            
            int top = (r > 0) ? grid[get_idx(r - 1, c)] : 0;
            int left = (c > 0) ? grid[get_idx(r, c - 1)] : 0;
            int topleft= (r > 0 && c > 0) ? grid[get_idx(r - 1, c - 1)] : 0;
            
            int val = diff[get_idx(r, c)] + top + left - topleft;
            grid[get_idx(r, c)] = val;
            
            if (val == 0 && !found) {
                found = true;
                best_pos = {r, c};
            }
        }
    }
    
    return found;
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    M = m;
    N = n;
    H = h;
    W = w;
    vector<int> answer;
    
    int low = 0;
    int high = drops.size();
    
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> pos;
        
        if (check(mid, drops, pos)) {
            answer = pos;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    return answer;
}