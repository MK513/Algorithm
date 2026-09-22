#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

#define MAX 10100

using namespace std;

unordered_map<string, int> name_pools;
int name_counter;
int parent[MAX], gain[MAX];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    name_pools.clear();
    fill(parent, parent + MAX, 0);
    fill(gain, gain + MAX, 0);
    name_counter = 1;
    
    // child parent 연결
    for (int i = 0; i < enroll.size(); i++) {
        
        // 이름 숫자 매칭
        if (name_pools[enroll[i]] == 0)
            name_pools[enroll[i]] = name_counter++;
        
        if (referral[i] == "-") continue;
        else if (name_pools[referral[i]] == 0)
            name_pools[referral[i]] = name_counter++;
        
        int c = name_pools[enroll[i]];
        int p = name_pools[referral[i]];
    
        parent[c] = p;
    }

    for (int i = 0; i < seller.size(); i++) {
        int s = name_pools[seller[i]];
        int cost = amount[i] * 100;
        
        while (s != 0 && cost > 0) {
            gain[s] += cost - (cost / 10);
            cost /= 10;
            s = parent[s];
        }
    }

    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        int t = name_pools[enroll[i]];
        answer.push_back(gain[t]);
    }
    
    return answer;
}