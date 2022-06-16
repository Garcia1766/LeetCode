#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // printf("Size of word set: %lu\n", wordSet.size());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        wordSet.erase(beginWord);
        int wd_len = beginWord.size();
        queue<pair<string, int>> que;  // <word, distance>
        que.push(make_pair(beginWord, 0));
        while (!que.empty()) {
            string wd = que.front().first;
            int dis = que.front().second;
            que.pop();
            if (wd == endWord) return dis + 1;
            for (int i = 0; i < wd_len; i++) {
                char c = wd[i];
                for (int j = 0; j < 26; j++) {
                    wd[i] = 'a' + j;
                    if (wordSet.find(wd) != wordSet.end()) {
                        que.push(make_pair(wd, dis + 1));
                        wordSet.erase(wd);
                    }
                }
                wd[i] = c;
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    int res = Solution().ladderLength(beginWord, endWord, wordList);
    printf("%d\n", res);
    return 0;
}