#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int answer, N;
bool row[15], col[15], diag_left[30], diag_right[30];

void nqueen(int r) {
    if (r >= N) {
        answer++;
        return;
    }
    
    for (int j = 0; j < N; j++) {
        
        if (row[r] || col[j] || diag_left[r + j] || diag_right[r - j + N]) continue;

        row[r] = true;
        col[j] = true;
        diag_left[r + j] = true;
        diag_right[r - j + N] = true;
        
        nqueen(r + 1);
        
        row[r] = false;
        col[j] = false;
        diag_left[r + j] = false;
        diag_right[r - j + N] = false;
    }
    
    return;
}

int solution(int n) {
    answer = 0;
    N = n;
    
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(diag_left, false, sizeof(diag_left));
    memset(diag_right, false, sizeof(diag_right));
    
    nqueen(0);
    
    return answer;
}