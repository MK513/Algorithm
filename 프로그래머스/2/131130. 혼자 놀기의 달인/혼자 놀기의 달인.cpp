#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_checked[110];
vector<int> group_sizes;

int calculate_group_size(int cur, vector<int> &cards) {
    int ret = 0;
    
    while (!is_checked[cur]) {
        is_checked[cur] = true;
        cur = cards[cur] - 1; 
        ret++;
    }
    return ret;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    fill(is_checked, is_checked + 110, false);
    
    for (int i = 0; i < cards.size(); i++) {
        if (is_checked[i]) continue;
        
        int cnt = calculate_group_size(i, cards);
        group_sizes.push_back(cnt);
    }
    
    if (group_sizes.size() == 1) {
        return 0;
    }
    sort(group_sizes.rbegin(), group_sizes.rend());
    
    answer = group_sizes[0] * group_sizes[1];
    return answer;
}