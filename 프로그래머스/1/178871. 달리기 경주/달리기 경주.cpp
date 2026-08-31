#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> ranks;


vector<string> solution(vector<string> players, vector<string> callings) {
    int cnt = 0;
    for (auto &p : players) {
        ranks[p] = cnt++;
    }
    
    for (auto &c : callings) {
        int cur = ranks[c];
        string front_player = players[cur - 1];
        
        swap(players[cur], players[cur - 1]);
        
        ranks[c] = cur - 1;
        ranks[front_player] = cur;
    }
    
    return players;
}