#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> result;

        for (int i = 0; i < nums2.size(); i++) {
            if (set1.find(nums2[i]) != set1.end()) {  // return end() if unsuccessful
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    int arr1[] = {4, 9, 5};
    int arr2[] = {9, 4, 9, 8, 4};
    vector<int> nums1(arr1, arr1+sizeof(arr1)/sizeof(int));
    vector<int> nums2(arr2, arr2+sizeof(arr2)/sizeof(int));

    vector<int> s = Solution().intersection(nums1, nums2);

    for(int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}