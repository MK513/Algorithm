#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>
#include <cmath>

using namespace std;

set<string> car_nums;
unordered_map<string, string> car_in_time;
unordered_map<string, int> total_time;


int calculate_time(string in_time, string out_time) {
    int in_hour = stoi(in_time.substr(0, 2));
    int in_minute = stoi(in_time.substr(3, 2));
    int out_hour = stoi(out_time.substr(0, 2));
    int out_minute = stoi(out_time.substr(3, 2));
    return (out_hour - in_hour) * 60 + (out_minute - in_minute);
}


vector<int> solution(vector<int> fees, vector<string> records) {
    
    string time, car_num, is_in;
    for (string rec : records) {
        stringstream r(rec);
        r >> time >> car_num >> is_in;
        
        // 차량 번호 기록
        car_nums.insert(car_num);
        
        // 입차시
        if (is_in == "IN") {
            // 전날 출차 기록이 없는 경우
            if (car_in_time[car_num] != "") {
                total_time[car_num] += calculate_time(car_in_time[car_num], "23:59");
            }
            car_in_time[car_num] = time;
        }
        // 출차시
        else {
            total_time[car_num] += calculate_time(car_in_time[car_num], time);
            car_in_time[car_num] = "";
        }
    }
    
    // 마지막날 출차기록 없는 경우 처리
    for (auto[car_num, in_t] : car_in_time) {
        if (in_t != "") {
            total_time[car_num] += calculate_time(car_in_time[car_num], "23:59");
        }
    }
    
    // 누적 시간 요금 계산
    int basic_time = fees[0];
    int basic_fee = fees[1];
    int unit_time = fees[2];
    int unit_fee = fees[3];
    
    vector<int> answer;
    for (string car : car_nums) {
        int fee = basic_fee;
        if (total_time[car] > basic_time) {
            fee += ceil(((float)total_time[car] - basic_time) / unit_time) * unit_fee;
        }
        answer.push_back(fee);
    }
    return answer;
}