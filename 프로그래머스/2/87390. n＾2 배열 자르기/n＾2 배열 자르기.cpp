#include <string>
#include <vector>

using namespace std;


/*
\ 0 1 2 3 4
0 1 2 3 4 5
1 2 2 3 4 5 
2 3 3 3 4 5
3 4 4 4 4 5
4 5 5 5 5 5

*/
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++) {
        long long div = i / n;
        long long rem = i % n;
        
        int num = max(div, rem) + 1;
        answer.push_back(num);
    }
    return answer;
}