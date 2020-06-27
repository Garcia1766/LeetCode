#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        for (; l < r; l++, r--) {
            if (s[l] != s[r])
                swap(s[l], s[r]);
        }
    }
};

int main() {
    char arr[] = {'H','a','n','n','a','h'};
    vector<char> vec(arr, arr+sizeof(arr)/sizeof(char));
    // string s = "A man, a plan, a canal: Panama";
    // string s1 = "race a car";

    Solution().reverseString(vec);

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}