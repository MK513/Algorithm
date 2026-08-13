#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

#define MAX 1000100

using namespace std;

bool visited[MAX];
vector<int> ne[MAX];

// 노드가 '루트일 때' 홀짝 노드인지 여부
bool isRootOddEven(int u) {
    int deg = ne[u].size();
    return (u % 2) == (deg % 2);
}

// 노드가 '루트일 때' 역홀짝 노드인지 여부
bool isRootReverse(int u) {
    int deg = ne[u].size();
    return (u % 2) != (deg % 2);
}

void dfs(int prev, int cur, vector<int> &element) {
    if (visited[cur]) return;
    
    element.push_back(cur);
    visited[cur] = true;
    
    for (int &nxt : ne[cur]) {
        if (nxt == prev) continue;
        dfs(cur, nxt, element);
    }
    
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    
    int odd_even = 0;
    int rev = 0;
    memset(visited, false, sizeof(visited));
    for (int n : nodes) {
        ne[n].clear();
    }

    for (auto& e : edges) {
        ne[e[0]].push_back(e[1]);
        ne[e[1]].push_back(e[0]);
    }
    
    for (int &n : nodes) {
        
        if (visited[n]) continue;
        
        vector<int> elements;
        dfs(0, n, elements);
        
        int odd_even_cnt = 0;
        int rev_cnt = 0;
        
        for (int &j : elements) {
            if (isRootOddEven(j)) odd_even_cnt++;
            if (isRootReverse(j)) rev_cnt++;
        }
        
        if (odd_even_cnt == 1) odd_even++;
        if (rev_cnt == 1) rev++;
    }
    
    return {odd_even, rev};
}