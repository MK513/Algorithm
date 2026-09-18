#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    
    int wf = scores[0][0];
    int ws = scores[0][1];
    int wsum = wf + ws;
    
    sort(scores.begin(), scores.end(), comp);
    
    int rank = 1;
    int top_s = scores[0][1];
    
    for (auto i : scores) {
        int cf = i[0];
        int cs = i[1];
        
        // 인센 불가 
        if (cs < top_s) {
            // 원호일 때
            if (cf == wf && cs == ws) return -1;
        }
        // 인센 가능
        else {
            top_s = cs;
            
            // 원호보다 점수 높으면 석차 밀림
            if (wsum < cf + cs) {
                rank++;
            }
        }
    }
    
    
    return rank;
}