#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delim) {
    vector<string> ret;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, delim)) ret.push_back(tmp);
    return ret;
}

string solution(string s) {
    vector<string> nums = split(s, ' ');
    
    // 배열의 첫 번째 값으로 초기화
    int mx = stoi(nums[0]);
    int mn = stoi(nums[0]);
    
    for (string num : nums) {
        // stoi는 음수를 자동으로 처리함
        int tnum = stoi(num); 
        
        mx = max(mx, tnum);
        mn = min(mn, tnum);
    }
    
    // (최솟값) (최댓값) 순서로 조합
    string answer = to_string(mn) + " " + to_string(mx);
    return answer;
}