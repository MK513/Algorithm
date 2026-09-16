#include <string>
#include <vector>
#include <algorithm>

#define ALPHABET 26

using namespace std;

vector<int> orders;

bool comp(const string& a, const string& b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

long long toNum(string s) {
    long long ret = 0;
    long long mul = 1;
    for (auto idx = s.rbegin(); idx != s.rend(); idx++) {
        ret += (*idx - 'a' + 1) * mul;
        mul *= ALPHABET;
    }
    return ret;
}

string toAlpha(long long n) {
    string ret = "";
    while (n > 0) {
        ret += ((n - 1)% ALPHABET) + 'a';
        n = (n - 1) / ALPHABET;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string solution(long long n, vector<string> bans) {
    
    sort(bans.begin(), bans.end(), comp);
    for (string &b : bans) {
        if (toNum(b) <= n) n++;
        else {
            break;
        }
    }
    
    return toAlpha(n);
}