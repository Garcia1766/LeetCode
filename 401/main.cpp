#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>

using namespace std;

void print_vector(vector<int> vec, bool newline = true){
    printf("[");
    for (int i = 0; i < vec.size(); i++)
        printf("%d,", vec[i]);
    printf("]");
    if (newline) printf("\n");
}

class Solution {
private:
    vector<string> res;
    vector<vector<int>> minute = {{0}, {1, 2, 4, 8, 16, 32},
        {3, 5, 9, 17, 33, 6, 10, 18, 34, 12, 20, 36, 24, 40, 48},
        {7, 11, 19, 35, 13, 21, 37, 25, 41, 49, 14, 22, 38, 26, 42, 50, 28, 44, 52, 56},
        {15, 23, 39, 27, 43, 51, 29, 45, 53, 57, 30, 46, 54, 58},
        {31, 47, 55, 59}};
    vector<vector<int>> hour = {{0}, {1, 2, 4, 8}, {3, 5, 9, 6, 10}, {7, 11}};

    string time_str(int h, int m) {
        if (m < 10) {
            return to_string(h) + ":0" + to_string(m);
        } else {
            return to_string(h) + ":" + to_string(m);
        }
    }
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn > 8) return res;
        for (int i = max(0, turnedOn - 5); i <= 3 && i <= turnedOn; i++) {
            vector<int> h_set = hour[i];
            vector<int> m_set = minute[turnedOn - i];
            for (int h : h_set) {
                for (int m : m_set) {
                    res.push_back(time_str(h, m));
                }
            }
        }
        return res;
    }
};

int main() {
    int turnedOn = 6;
    vector<string> res = Solution().readBinaryWatch(turnedOn);
    for (int i = 0; i < res.size(); i++) {
        printf("%s, ", res[i].c_str());
    } printf("\n");
    return 0;
}
