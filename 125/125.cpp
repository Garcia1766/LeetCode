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
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;
        
        int l = 0, r = s.length() - 1;
        while (l < s.length() && r >= 0 && l < r) {
            while (!isalnum(s[l])) {
                l++;
                if (l >= s.length())
                    return true;
            }
            while (!isalnum(s[r])) r--;
            if ( !((isdigit(s[l]) && s[l] == s[r]) || (isalpha(s[l]) && tolower(s[l]) == tolower(s[r]))) )
                return false;
            l++; r--;
        }
        return true;
    }
};

int main() {
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
    string s = "A man, a plan, a canal: Panama";
    string s1 = "race a car";

    cout << Solution().isPalindrome(s) << endl;

    // for(int i=0; i<vec.size(); i++) {
    //     cout << vec[i] << " ";
    // }
    // cout << endl;

    return 0;
}