#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0, csize;
vector<int> bag;

void checkValidation(vector<vector<int>> &q, vector<int> &ans) {
    for (int i = 0; i < q.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (q[i][j] == bag[k]) {
                    cnt++; break;
                }
                
            }
        }
        
        if (cnt != ans[i]) {
            return;
        }
    }
    
    answer++;
    return;
}

void backtrack(int n, vector<vector<int>> &q, vector<int> &ans, int cur) {
    if (bag.size() >= 5) {
        checkValidation(q, ans);
        return;
    }
    
    for (int i = cur + 1; i <= n; i++) {
        bag.push_back(i);
        backtrack(n, q, ans, i);
        bag.pop_back();
    }
    
    return;
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    
    csize = q.size();
    backtrack(n, q, ans, 0);
    
    return answer;
}