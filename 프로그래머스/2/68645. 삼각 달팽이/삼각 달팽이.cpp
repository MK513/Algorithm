#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int arr[1010][1010];

vector<int> solution(int n) {
    
    memset(arr, -1, sizeof(arr));
    
    int x = -1, y = 0, num = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i % 3 == 0) x++;
            else if (i % 3 == 1) y++;
            else if (i % 3 == 2) {
                x--; y--;
            }
            
            arr[x][y] = num++;
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == -1) break;
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}