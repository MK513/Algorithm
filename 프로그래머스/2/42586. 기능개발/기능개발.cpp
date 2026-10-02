#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int ptr = 0;
    while (1) {
        
        while (progresses[ptr] < 100) {
            for (int i = 0; i < progresses.size(); i++) {
                progresses[i] += speeds[i];
            }
        }
        
        int cnt = 0;
        while (progresses[ptr] >= 100) {
            cnt++;
            ptr++;
            if (ptr >= progresses.size()) break;
        }
        answer.push_back(cnt);
        
        if (ptr >= progresses.size()) break;
    }
    return answer;
}