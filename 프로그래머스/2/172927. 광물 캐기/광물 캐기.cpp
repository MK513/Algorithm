#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int N;
int values[20][3]; // 0 : 다이아, 1 : 철, 2 : 돌

int backtrack(int dia, int iron, int stone, int cnt) {
    if (dia == 0 && iron == 0 && stone == 0) {
        return 0;
    }
    if (N < cnt) {
        return 0;
    }
    
    int ret = 1e9;
    if (dia > 0) {
        ret = min(ret, backtrack(dia - 1, iron, stone, cnt + 1) + values[cnt][0]);
    }
    if (iron > 0) {
        ret = min(ret, backtrack(dia, iron - 1, stone, cnt + 1) + values[cnt][1]);
    }
    if (stone > 0) {
        ret = min(ret, backtrack(dia, iron, stone - 1, cnt + 1) + values[cnt][2]);
    }
    
    return ret;
}

int solution(vector<int> picks, vector<string> minerals) {
    memset(values, 0, sizeof(values));
    
    N = minerals.size() / 5;

    for (int i = 0; i < minerals.size(); i++) {
        if (minerals[i] == "diamond") {
            values[i / 5][0] += 1;
            values[i / 5][1] += 5;
            values[i / 5][2] += 25;
        }
        else if (minerals[i] == "iron") {
            values[i / 5][0] += 1;
            values[i / 5][1] += 1;
            values[i / 5][2] += 5;
        }
        else if (minerals[i] == "stone") {
            values[i / 5][0] += 1;
            values[i / 5][1] += 1;
            values[i / 5][2] += 1;
        }
    }
    
    return backtrack(picks[0], picks[1], picks[2], 0);
}