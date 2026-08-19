#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long w1 = (long long)r1 * r1;
    long long w2 = (long long)r2 * r2;
    
    for (int i = 1; i <= r2; i++) {
        // 바깥 원의 Y 최대값 (내림)
        long long max_y = sqrt(w2 - (long long)i * i);
    
        // 안쪽 원의 Y 최소값 (올림)
        long long min_y = 0;
        if (i < r1) {
            long long rem = w1 - (long long)i * i;
            min_y = sqrt(rem);
            if (min_y * min_y < rem) min_y++; // 딱 떨어지지 않으면 올림
        }
        answer += max_y - min_y + 1;
    }
    answer *= 4;
    return answer;
}