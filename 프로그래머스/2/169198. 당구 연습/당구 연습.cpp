#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto &ball : balls) {
        int x = ball[0];
        int y = ball[1];
        int min_dist = 1e9;
        
        if (!(startY == y && startX > x)) {
            int dist = (startX - (-x)) * (startX - (-x)) + (startY - y) * (startY - y);
            min_dist = min(min_dist, dist);
        }
        
        if (!(startY == y && startX < x)) {
            int dist = (startX - (2 * m - x)) * (startX - (2 * m - x)) + (startY - y) * (startY - y);
            min_dist = min(min_dist, dist);
        }
        
        if (!(startX == x && startY > y)) {
            int dist = (startX - x) * (startX - x) + (startY - (-y)) * (startY - (-y));
            min_dist = min(min_dist, dist);
        }
        
        if (!(startX == x && startY < y)) {
            int dist = (startX - x) * (startX - x) + (startY - (2 * n - y)) * (startY - (2 * n - y));
            min_dist = min(min_dist, dist);
        }
        
        answer.push_back(min_dist);
    }
    return answer;
}