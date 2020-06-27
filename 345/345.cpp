#include<iostream>
#include<cmath>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = s.length() - 1;
        for (; l < r; ) {
            while (!isVowel(s[l]) && l < r) l++;
            while (!isVowel(s[r]) && l < r) r--;
            if (l == r) return s;
            swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main() {
    char arr[] = {'H','a','n','n','a','h'};
    vector<char> vec(arr, arr+sizeof(arr)/sizeof(char));
    string s = "";

    s = Solution().reverseVowels(s);

    for(int i=0; i<s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}