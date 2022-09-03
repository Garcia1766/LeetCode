#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cassert>
#include<unordered_map>
#include<algorithm>
#include<bitset>

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
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>(h<<6 | m).count() == turnedOn) {
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
