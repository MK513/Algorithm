#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

bool comp(const pii& a, const pii& b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    
    map<int, int> type_set;
    for (int i = 0; i < tangerine.size(); i++) {
        int type = tangerine[i];
        type_set[type]++;
    }
    
    vector<pii> types(type_set.begin(), type_set.end());
    sort(types.begin(), types.end(), comp);
    
    int answer = 0;
    for (auto [t, cnt] : types) {
        k -= cnt;
        answer++;
        
        if (k <= 0) break;
    }
    
    return answer;
}