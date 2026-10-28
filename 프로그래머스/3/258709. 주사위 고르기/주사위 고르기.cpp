#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long ll;

int N, max_win;
ll best_bit;
bool visited[1 << 10];
vector<vector<int>> Dice;


vector<int> to_vector_dice(ll bit) {
    vector<int> ret;
    for (int i = 0; i < N; i++) {
        if (bit & (1 << i)) {
            ret.push_back(i);
        }
    }
    return ret;
}

void get_all(const vector<int> &d, int idx, int nsum, vector<int> &target) {
    if (idx == N / 2) {
        target.push_back(nsum);
        return;
    }
    
    int cur = d[idx];
    for (int i = 0; i < 6; i++) {
        get_all(d, idx + 1, nsum + Dice[cur][i], target);
    }
}

void check_answer(ll bit) {
    int win = 0, draw = 0, lose = 0;
    vector<int> selected = to_vector_dice(bit);
    vector<int> opposite = to_vector_dice(((1 << N) - 1) ^ bit);
    
    vector<int> comb, oppo;
    get_all(selected, 0, 0, comb);
    get_all(opposite, 0, 0, oppo);
    
    sort(comb.begin(), comb.end());
    sort(oppo.begin(), oppo.end());
    
    for (int c : comb) {
        win += lower_bound(oppo.begin(), oppo.end(), c) - oppo.begin();
    }
    
    for (int o : oppo) {
        lose += lower_bound(comb.begin(), comb.end(), o) - comb.begin();
    }
    
    if (win > max_win) {
        max_win = win;
        best_bit = bit;
    }
    
    if (lose > max_win) {
        max_win = lose;
        best_bit = ((1 << N) - 1) ^ bit;
    }
}

void dfs(int cnt, ll bit) {
    if (cnt >= N / 2) {
        if (visited[bit]) return;
        
        visited[bit] = true;
        visited[((1 << N) - 1) ^ bit] = true;
        check_answer(bit);
        return;
    }
    
    for (int i = 0; i < N; i++) {
        if (bit & (1 << i)) continue;
        dfs(cnt + 1, bit | (1 << i));
    }
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    Dice = dice;
    
    max_win = 0;
    dfs(0, 0);
    
    vector<int> ans = to_vector_dice(best_bit);
    for (int &i : ans) i++;
    return ans; 
}