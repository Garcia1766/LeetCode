#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        int k=0;
        for (int i=1; i<nums.size(); i++) {
            if(nums[i] != nums[k]) {
                k++;
                if(i > k)
                    nums[k] = nums[i];
            }
        }

        return k+1;
    }
};

int main() {
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    cout << Solution().removeDuplicates(vec) << endl;

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}