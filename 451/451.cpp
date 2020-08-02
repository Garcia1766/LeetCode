#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map1;
        for (int i = 0; i < s.size(); i++) {
            map1[s[i]]++;
        }
        priority_queue<pair<int, char>> queue1;
        for (auto it = map1.begin(); it != map1.end(); it++) {
            queue1.push({it->second, it->first});
        }
        string ans;
        while (!queue1.empty()) {
            int freq = queue1.top().first;
            char c = queue1.top().second;
            for (int i = 0; i < freq; i++)
                ans.push_back(c);
            queue1.pop();
        }
        return ans;
    }
};

int main() {
    cout << Solution().frequencySort("Aabb") << endl;

    return 0;
}
