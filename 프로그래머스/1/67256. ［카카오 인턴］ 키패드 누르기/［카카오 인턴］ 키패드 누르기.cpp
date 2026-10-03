#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

pii pos[10] = {
    {3, 1}, // 0
    {0, 0}, {0, 1}, {0, 2}, // 1, 2, 3
    {1, 0}, {1, 1}, {1, 2}, // 4, 5, 6
    {2, 0}, {2, 1}, {2, 2}  // 7, 8, 9
};

int get_dist(pii &a, pii &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    pii lpos = {3, 0};
    pii rpos = {3, 2};
    
    for (int num : numbers) {
        if (num == 1 || num == 4 || num == 7) {
            answer += "L";
            lpos = pos[num];
        }
        else if (num == 3 || num == 6 || num == 9) {
            answer += "R";
            rpos = pos[num];
        }
        else { // 2, 5, 8, 0
            int ldis = get_dist(lpos, pos[num]);
            int rdis = get_dist(rpos, pos[num]);
            
            bool use_left = (ldis < rdis || (ldis == rdis && hand == "left")) ? true : false;
            
            if (use_left) {
                answer += "L";
                lpos = pos[num];
            }
            else {
                answer += "R";
                rpos = pos[num];
            }
        }
    }
    
    return answer;
}