#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<string> vec_str(strs);
//         for (int i = 0; i < vec_str.size(); i++)
//             sort(vec_str[i].begin(), vec_str[i].end());
        
//         unordered_map<string, vector<int>> map1;
//         for (int i = 0; i < vec_str.size(); i++)
//             map1[vec_str[i]].push_back(i);
        
//         vector<vector<string>> ans;
//         // unordered_map<string, vector<int>>::iterator iter;
//         // for (iter = map1.begin(); iter != map1.end(); iter++) {
//         //     vector<string> grp;
//         //     for (int i = 0; i < iter->second.size(); i++)
//         //         grp.push_back(strs[iter->second[i]]);
//         //     ans.push_back(grp);
//         // }
//         for (auto p : map1) {
//             vector<string> grp;
//             for (int i = 0; i < p.second.size(); i++)
//                 grp.push_back(strs[p.second[i]]);
//             ans.push_back(grp);
//         }
//         return ans;
//     }
// };

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

vector<int> generate_primes(int n) {
    vector<int> ans;
    int cnt = 0;
    for (int i = 2; cnt < n; i++) {
        if (is_prime(i)) {
            ans.push_back(i);
            cnt++;
        }
    }
    return ans;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> primes = generate_primes(26);
        unordered_map<double, vector<string>> map1;
        for (string str : strs) {
            double tmp = 1;
            for (char c : str)
                tmp *= primes[c - 'a'];
            map1[tmp].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto p : map1)
            ans.push_back(p.second);
        return ans;
    }
};

int main() {
    string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs(arr, arr + 6);
    vector<vector<string>> ans  = Solution().groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
