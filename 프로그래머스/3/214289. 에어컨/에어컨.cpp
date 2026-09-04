#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;
int dp[1010][60]; // 시간, 현재 온도

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    
    // temperature +10 보정
    temperature += 10;
    t1 += 10;
    t2 += 10;
    
    // 외부 온도가 이상 온도 이내에 존재하는 경우
    if (t1 <= temperature && temperature <= t2) {
        return 0;
    }
    
    int dir_air = 1;
    
    fill(&dp[0][0], &dp[0][0] + 1010 * 60, INF);
    dp[0][temperature] = 0;

    if (t2 < temperature) dir_air = -1;
    
    for (int i = 1; i < onboard.size(); i++) {
        
        for (int j = 0; j <= 50; j++) {
            
            // 승객 탔을 때 쾌적온도 아닌곳 블러 처리
            if (onboard[i] == 1 && (j < t1 || j > t2)) {
                continue;
            }
            
            // 온도 유지
            if (j == temperature) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i - 1][j] + b;
            }
            
            if (j - 1 >= 0) {
                if (j - 1 < temperature) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a);
                }
            }
            
            if (j + 1 <= 50) {
                if (j + 1 > temperature) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a);
                }
            }
        }
    }
    
    int answer = INF;
    for (int i = 0; i <= 50; i++) {
        answer = min(answer, dp[onboard.size() - 1][i]);        
    }
    
    return answer;
}