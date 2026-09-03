#include <string>
#include <vector>

using namespace std;

int count_by_angle(int h, int m, int s) {
    int angle_h = 0;
    int angle_m = 0;
    int angle_s = 0;
    
    int cnt = 0;
    int total_s = h * 3600 + m * 60 + s;
    
    // 모든 각도에 120을 곱해서 연산하여 부동소수점 문제 차단
    for (int i = 0; i < total_s; i++) {
        
        // 1. 현재 위치
        int s_cur = angle_s % 43200;
        int m_cur = angle_m % 43200;
        int h_cur = angle_h % 43200;

        // 2. 1초 뒤의 위치
        int s_nxt = (angle_s + 720) % 43200 == 0 ? 43200 : (angle_s + 720) % 43200;
        int m_nxt = (angle_m + 12) % 43200 == 0 ? 43200 : (angle_m + 12) % 43200;
        int h_nxt = (angle_h + 1) % 43200 == 0 ? 43200 : (angle_h + 1) % 43200;

        // 3. 지나갈때 카운팅
        if (s_cur < m_cur && s_nxt >= m_nxt) {
            cnt++;
        }
        if (s_cur < h_cur && s_nxt >= h_nxt) {
            cnt++;
        }
    
        // 4. 0시 예외 처리
        if (s_nxt == m_nxt && m_nxt == h_nxt) {
            cnt--;
        }
            
        angle_s += 720;
        angle_m += 12;
        angle_h += 1;
        
        if (angle_s >= 43200) angle_s = 0;
        if (angle_m >= 43200) angle_m = 0;
        if (angle_h >= 43200) angle_h = 0;
    }

    return cnt;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = -1;
    
    answer = count_by_angle(h2, m2, s2) - count_by_angle(h1, m1, s1);
    
    // 시작 시간 예외 처리
    if ((h1 == 12 || h1 == 0) && m1 == 0 && s1 == 0) answer++;
    
    return answer;
}