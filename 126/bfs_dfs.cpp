#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.insert(beginWord);
        unordered_map<string, unordered_set<string>> neighbors;
        unordered_map<string, int> distance;
        vector<string> sol;
        vector<vector<string>> ans;

        bfs(beginWord, endWord, wordSet, neighbors, distance);
        // for (auto iter : distance) printf("(%s, %d) ", iter.first.c_str(), iter.second);
        // printf("\n");
        // for (auto iter : neighbors) {
        //     printf("%s: ", iter.first.c_str());
        //     for (auto it : iter.second) printf("%s ", it.c_str());
        //     printf("\n");
        // }
        dfs(beginWord, endWord, wordSet, neighbors, distance, sol, ans);

        return ans;
    }
private:
    void bfs(string beginWord, string endWord, unordered_set<string>& wordSet, 
    unordered_map<string, unordered_set<string>>& neighbors, unordered_map<string, int>& distance) {
        int wd_size = beginWord.size();
        queue<string> q({beginWord});
        neighbors.insert(make_pair(beginWord, unordered_set<string>()));
        distance.insert(make_pair(beginWord, 0));
        bool reached = false;
        while(!q.empty() && !reached) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < wd_size; i++) {
                    string tmp = cur;
                    for (int j = 0; j < 26; j++) {
                        tmp[i] = 'a' + j;
                        if (wordSet.find(tmp) != wordSet.end()) {
                            if (distance.find(tmp) == distance.end()) {
                                distance.insert(make_pair(tmp, distance[cur] + 1));
                                neighbors.insert(make_pair(tmp,  unordered_set<string>()));
                                neighbors[cur].insert(tmp);
                                q.push(tmp);
                            } else if (distance[tmp] == distance[cur] + 1) {
                                neighbors[cur].insert(tmp);
                            }
                            if (tmp == endWord) reached = true;
                        }
                    }
                }
            }
        }
    }
    void dfs(string cur, string endWord, unordered_set<string>& wordSet, unordered_map<string, unordered_set<string>>& neighbors,
    unordered_map<string, int>& distance, vector<string>& sol, vector<vector<string>>& ans) {
        sol.push_back(cur);
        if (cur == endWord) {
            ans.push_back(sol);
        } else {
            for (string nxt : neighbors[cur]) {
                dfs(nxt, endWord, wordSet, neighbors, distance, sol, ans);
            }
        }
        sol.pop_back();
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