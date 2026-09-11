#include <string>
#include <vector>

using namespace std;

bool is_painted[100100];

int solution(int n, int m, vector<int> section) {
    fill(is_painted, is_painted + 100100, true);
    
    for (int i : section) {
        is_painted[i] = false;
    }
    
    int answer = 0;
    for (int i : section) {
        if (is_painted[i]) continue;
        
        answer++;
        for (int j = i; j <= n && j < i + m; j++) {
            is_painted[j] = true;
        }
    }
    
    return answer;
}