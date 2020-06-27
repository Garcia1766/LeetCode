#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if (numbers[l] + numbers[r] == target) {
                int arr[] = {l+1, r+1};
                return vector<int>(arr, arr+2);
            } else if (numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        throw invalid_argument("The input has no solution.");
    }
};

int main() {
    int arr[] = {2,7,11,15}, target = 9;
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

    vector<int> ans = Solution().twoSum(vec, target);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}