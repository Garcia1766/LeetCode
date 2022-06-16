#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        int wd_len = beginWord.size();
        q.push({beginWord});
        bool reached = false;
        while(!q.empty() && !reached) {
            int size = q.size();
            while(size--) {
                vector<string> path = q.front();
                q.pop();
                string last = path.back();
                for (int i = 0; i < wd_len; i++) {
                    char c = last[i];
                    for (int j = 0; j < 26; j++) {
                        last[i] = 'a' + j;
                        if (wordSet.find(last) != wordSet.end()) {
                            vector<string> new_path = path;
                            new_path.push_back(last);
                            visited.insert(last);
                            if (last == endWord) {
                                ans.push_back(new_path);
                                reached = true;
                            } else {
                                q.push(new_path);
                            }
                        }
                    }
                    last[i] = c;
                }
            }
            for (auto wd : visited)
                wordSet.erase(wd);
        }
        return ans;
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> res = Solution().findLadders(beginWord, endWord, wordList);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++)
            printf("%s ", res[i][j].c_str());
        printf("\n");
    }
    printf("\n");
    return 0;
}