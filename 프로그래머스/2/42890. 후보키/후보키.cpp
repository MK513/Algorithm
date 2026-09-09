#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<int> chosen, answers;

void is_candidate(vector<vector<string>> &relation) {
    
    // 최소성 확인
    int bitmask = 0;
    for (int i : chosen) {
        bitmask += (1 << i);
    }
    for (int &a : answers) {
        if ((a & bitmask) == a) return;
    }
    
    unordered_map<string, bool> isExist;
    
    // 유일성 확인
    for (auto row : relation) {
        string key = "";
        for (int i : chosen) {
            key += row[i];
        }
        
        // 중복 확인 시 종료
        if (isExist[key]) return;
        isExist[key] = true;
    }
    
    // 정답에 인덱스 문자열 추가
    answers.push_back(bitmask);
}

void backtrack(vector<vector<string>> &relation, int sz, int cnt, int t) {
    if (sz == cnt) {
        is_candidate(relation);
        return;
    }
    
    for (int i = t; i < N; i++) {
        chosen.push_back(i);
        backtrack(relation, sz, cnt + 1, i + 1);
        chosen.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    N = relation[0].size();
    
    // 백트래킹으로 모든 경우의 수 만들기
    for (int i = 1; i <= N; i++) {
        chosen.clear();
        backtrack(relation, i, 0, 0);
    }
    
    return answers.size();
}