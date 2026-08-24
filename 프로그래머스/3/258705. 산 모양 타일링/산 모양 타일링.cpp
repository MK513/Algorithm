#include <string>
#include <vector>

#define MAX 100010

using namespace std;

int DP[MAX * 2 + 1];

int solution(int n, vector<int> tops) {
    
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= n * 2 + 1; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
        
        // 뿔 있을때, 2부터 짝수단위로 체크
        if (i % 2 == 0 && tops[i / 2 - 1]) {
            DP[i] = (DP[i] + DP[i - 1]) % 10007;
        }
    }
    return DP[n * 2 + 1];
}