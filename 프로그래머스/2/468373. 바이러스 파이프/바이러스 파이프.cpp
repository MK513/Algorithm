#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

int n, answer;
vector<pii> edge[110]; // from, (to, type)
bool infected[110];
int types[3] = {1, 2, 3};

int countInfected() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (infected[i])  {
            cnt++;
        }
    }
    return cnt;
}

void backtrack(int cur_type, int k) {
    if (k == 0) {
        answer = max(answer, countInfected());
        return;
    }
    
    // infect
    deque<int> dq;
    bool tmp_infected[110];
    memcpy(tmp_infected, infected, sizeof(infected));
    for (int i = 0; i <= n; i++) {
        if (tmp_infected[i]) {
            dq.push_back(i);
        }
    }
    while (!dq.empty()) {
        int front = dq.front();
        dq.pop_front();
        
        for (auto e : edge[front]) {
            if (e.second == cur_type && !infected[e.first]) {
                dq.push_back(e.first);
                infected[e.first] = true;
            }
        }
    }
    
    for (int t : types) {
        if (t == cur_type) continue;
        backtrack(t, k - 1);
    }
    // rollback
    memcpy(infected, tmp_infected, sizeof(tmp_infected));
    
    return;
}

int solution(int _n, int infection, vector<vector<int>> _edges, int k) {
    n = _n;
    
    memset(infected, false, sizeof(infected));
    
    for (auto e : _edges) {
        edge[e[1]].push_back({e[0], e[2]});
        edge[e[0]].push_back({e[1], e[2]});
    }
    
    answer = 0;
    infected[infection] = true;
    for (int i : types) {
        backtrack(i, k);
    }
    
    return answer;
}