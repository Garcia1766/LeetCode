#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
int _partition(vector<T>& arr, int l, int r) { // [l, ..., r]
    swap(arr[l], arr[rand()%(r-l+1) + l]);  // let pivot = arr[l]
    int m = l, done = l + 1; // [l+1, ..., m] < pivot, [m+1, ..., done) > pivot
    for (; done <= r; done++)
        if (arr[done] < arr[l])
            swap(arr[++m], arr[done]);
    swap(arr[l], arr[m]);
    return m;
}

template<typename T>
T selection(vector<T>& arr, int l, int r, int k) {
    if(l == r)
        return arr[l];
    
    int p = _partition(arr, l, r);
    if(p == k)
        return arr[p];
    else if(k < p) 
        return selection(arr, l, p-1, k);
    else
        return selection(arr, p+1, r, k);
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];
        return selection(nums, 0, nums.size()-1, nums.size()-k);
    }
};

int main() {
    int nums1[] = {3,2,3,1,2,4,5,5,6}, k = 4;
    int nums2[] = {2,5,6},       n = 3;
    vector<int> vec1(nums1, nums1+sizeof(nums1)/sizeof(int));
    vector<int> vec2(nums2, nums2+sizeof(nums2)/sizeof(int));

    cout << Solution().findKthLargest(vec1, k) << endl;

    for(int i=0; i<vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    return 0;
}