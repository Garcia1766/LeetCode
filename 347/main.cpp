#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // O(n log k)
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // <num, freq>
        for (auto num : nums)
            freq[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <freq, num>
        for (auto iter : freq) {
            if (pq.size() >= k) {
                if (iter.second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(iter.second, iter.first));
                }
            } else
                pq.push(make_pair(iter.second, iter.first));
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    // O(n log(n-k))
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  // <num, freq>
        for (auto num : nums)
            freq[num]++;
        int sz = freq.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // <freq, num>
        vector<int> ans;
        for (auto iter : freq) {
            pq.push(make_pair(iter.second, iter.first));
            if (pq.size() > sz - k) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
    void print_map(unordered_map<int, int>& mp) {
        for (auto it : mp) {
            printf("(%d,%d)", it.first, it.second);
        } printf("\n");
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> ans = Solution().topKFrequent(nums, k);
    for (auto i : ans) {
        printf("%d ", i);
    } printf("\n");
    return 0;
}