#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<vector>

using namespace std;

template<typename T> void swap(vector<T>& arr, T i, T j) {
    T tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size();
        for (int i=0; i<two; ) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2) {
                two--;
                swap(nums, i, two);
            }
            else {
                assert(nums[i] == 0);
                zero++;
                swap(nums, i, zero);
                i++;
            }
        }
    }
};

int main() {
    int arr[] = {2,0,2,1,1,0};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    Solution().sortColors(vec);

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}