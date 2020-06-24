#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for (int i=0; i<nums.size(); i++) {
            if(nums[i]) {
                if(i != k) {
                    int t=nums[i];
                    nums[i]=nums[k];
                    nums[k]=t;
                }
                k++;
            }
        }
    }
};

int main() {
    int arr[] = {0, 1, 0, 3, 12, 0, 5, 7, 0};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    Solution().moveZeroes(vec);

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}