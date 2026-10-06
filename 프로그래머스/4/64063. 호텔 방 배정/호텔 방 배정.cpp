#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> parent;

ll Find(ll a) {
    // 처음 사용 되면 다음으로 큰 숫자 넣고 기록
    if (parent.count(a) == 0) {
        parent[a] = a + 1;
        return a;
    }
    // 아니면 올라가서 찾아오기
    return parent[a] = Find(parent[a]);
}

// 유니온 파인드 변형 인듯
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    parent.clear();
    
    for (int i = 0; i < room_number.size(); i++) {
        ll t = Find(room_number[i]);
        answer.push_back(t);
    }

    return answer;
}