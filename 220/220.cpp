#include<iostream>
#include<set>
#include<vector>

#define ll long long

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<ll> set1;
        for (int i = 0; i < nums.size(); i++) {
            if (set1.lower_bound((ll)nums[i] - (ll)t) != set1.end() && 
                *set1.lower_bound((ll)nums[i] - (ll)t) <= (ll)nums[i] + (ll)t) {
                return true;
            }
            set1.insert(nums[i]);
            if (set1.size() == k + 1)
                set1.erase(nums[i - k]);
        }
    }
};