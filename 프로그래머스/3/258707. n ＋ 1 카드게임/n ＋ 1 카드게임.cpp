#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int used_coin, x, y;
} Node;

int N;
bool in_hands[1010], debts[1010];

bool comp(const Node &a, const Node &b) {
    return a.used_coin < b.used_coin;
}

int solution(int coin, vector<int> cards) {
    
    fill(debts, debts + 1010, false);
    fill(in_hands, in_hands + 1010, false);
    
    N = cards.size();
    
    // 초기 핸드 세팅
    for (int i = 0; i < N / 3; i++) {
        in_hands[cards[i]] = true;
    }
    
    // 라운드 증가 시키며 체크
    int answer = 1;
    
    for (int i = N / 3; i < N; i += 2) {
        int first = cards[i];
        int second = cards[i + 1];
        
        in_hands[first] = true;
        in_hands[second] = true;
        
        debts[first] = true;
        debts[second] = true;
        
        // 핸드 조합 확인
        vector<Node> candidates;
        for (int j = 1; j <= N / 2; j++) {
            
            int t = N + 1 - j;
            
            // 조합 성공 시 후보로 추가
            if (in_hands[j] && in_hands[t]) {
                
                
                // 코인 0, 1개 일때 후보 제외 처리
                if (coin == 1 && debts[j] && debts[t]) {
                    continue;
                }
                else if (coin <= 0 && (debts[j] || debts[t])) {
                    continue;
                }
                
                candidates.push_back({debts[j] + debts[t], j, t});
            }
        }
        
        // 후보 없으면 종료
        if (candidates.empty()) break;
        // 있으면 코인 가장 적게 쓰는 거 사용
        else { 
            sort(candidates.begin(), candidates.end(), comp);
            
            Node t = candidates[0];
            
            in_hands[t.x] = false;
            in_hands[t.y] = false;
            
            if (debts[t.x]) {
                debts[t.x] = false;
                coin--;
            }
            
            if (debts[t.y]) {
                debts[t.y] = false;
                coin--;
            }
            
            answer++;
        }
    }
    
    return answer;
}