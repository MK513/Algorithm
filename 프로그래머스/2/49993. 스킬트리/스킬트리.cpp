#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    bool isChecked[30];
    
    fill(isChecked, isChecked + 30, false);
    for (auto &s : skill) {
        isChecked[s - 'A'] = true;
    }
    
    
    for (string &tree : skill_trees) {
        
        int idx = 0;
        bool isPossible = true;
        
        for (auto s : tree) {
            
            if (idx >= skill.size()) {
                break;
            }
            
            if (s == skill[idx]) {
                idx++;
            }
            else if (isChecked[s - 'A']) {
                isPossible = false;
                break;
            }
        }
        
        if (isPossible) answer++;
    }
    return answer;
}