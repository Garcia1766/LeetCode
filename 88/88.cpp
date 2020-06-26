#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--)
            nums1[i + n] = nums1[i];
        int p1 = n, p2 = 0, sorted = 0;
        for (; p2 < n; ) {
            nums1[sorted++] = (p1 >= m + n || nums2[p2] < nums1[p1]) ? nums2[p2++] : nums1[p1++];
        }
    }
};

int main() {
    int nums1[] = {1,2,3,0,0,0}, m = 3;
    int nums2[] = {2,5,6},       n = 3;
    vector<int> vec1(nums1, nums1+sizeof(nums1)/sizeof(int));
    vector<int> vec2(nums2, nums2+sizeof(nums2)/sizeof(int));

    Solution().merge(vec1, m, vec2, n);

    for(int i=0; i<vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;
    for(int i=0; i<vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    return 0;
}