#include <string>
#include <vector>
#include <numeric>

using namespace std;

int GCD(int a, int b) {
    int tmp;
    while (b > 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int LCM(int a, int b) {
    int gcd = GCD(a, b);
    return (a / gcd) * b;
}

int get_LCM(vector<int>& arr) {
    int ret = 0;
    for (int len : arr) {
        if (ret == 0) {
            ret = len;
            continue;
        }
        ret = LCM(ret, len);
    }
    return ret;
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    vector<int> len_arr;
    for (auto s : signals) {
        len_arr.push_back(accumulate(s.begin(), s.end(), 0));
    }
    
    int max_time = get_LCM(len_arr);
    
    for (int t = 1; t <= max_time; t++) {
        bool isPossible = true;
        
        for (int s = 0; s < signals.size(); s++) {
            int rem = t % len_arr[s];
            int G = signals[s][0];
            int Y = signals[s][1];
            
            if (rem <= G || rem > G + Y) {
                isPossible = false;
                break;
            }
            
        }
        
        if (isPossible) {
            answer = t;
            break;
        }
    }
    
    
    
    return answer;
}

