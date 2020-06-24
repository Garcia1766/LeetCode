#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                if (i != k) {
                    nums[k] = nums[i];
                }
                k++;
            }
        }
        return k;
    }
};

int main() {
    int arr[] = {0, 1, 2, 2, 3, 0, 4, 2};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    cout << Solution().removeElement(vec, 2) << endl;

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}