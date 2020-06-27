#include<iostream>
#include<cmath>
#include<ctime>
#include<cassert>
#include<algorithm>
#include<vector>

using namespace std;

/*
  1 2 3 4 5 6
1 x ------- o
2 x x
3 x x x 
4 x x x x
5 x x x x x
6 x x x x x x

  1 2 3 4 5 6
1 x ------- o
2 x x       o
3 x x x     |
4 x x x x   |
5 x x x x x |
6 x x x x x x

  1 2 3 4 5 6
1 x ------- o
2 x x - o o o
3 x x x o | |
4 x x x x | |
5 x x x x x |
6 x x x x x x
*/

int calArea(int w, int h1, int h2) {
    return w * min(h1, h2);
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = calArea(r-l, height[l], height[r]);
        while(l < r) {
            if (height[l] < height[r]) l++;
            else r--;
            if (calArea(r-l, height[l], height[r]) > ans)
                ans = calArea(r-l, height[l], height[r]);
        }
        return ans;
    }
};

int main() {
    int arr[] = {1,8,6,2,5,4,8,3,7};
    vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

    cout << Solution().maxArea(vec) << endl;

    return 0;
}