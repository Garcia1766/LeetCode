#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1;
        for (int i = 0; i<nums1.size(); i++) {
            map1[nums1[i]]++;
        }

        vector<int> result;

        for (int i = 0; i<nums2.size(); i++) {
            if (map1[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                map1[nums2[i]]--;
            }
        }
        return result;
    }
};

int main() {
    int arr1[] = {1, 2, 2, 1};
    int arr2[] = {2, 2};
    vector<int> nums1(arr1, arr1+sizeof(arr1)/sizeof(int));
    vector<int> nums2(arr2, arr2+sizeof(arr2)/sizeof(int));

    vector<int> s = Solution().intersect(nums1, nums2);

    for(int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}