#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
    int dis[500][500] = {0};
    // void init_dis() {
    //     for (int i = 0; i < 500; i++)
    //         for (int j = 0; j < 500; j++)
    //             dis[i][j] = -1;
    // }
    int dist(vector<int> a, vector<int> b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // init_dis();
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> map1;
            for (int j = 0; j < points.size(); j++)
                if (j != i) {
                    if (dis[i][j] == 0) {
                        dis[i][j] = dis[j][i] = dist(points[i], points[j]);
                    }
                    map1[dis[i][j]]++;
                }
            for (auto iter : map1)
                if (iter.second >= 2)
                    ans += iter.second * (iter.second - 1);
        }
        return ans;
    }
};

int main() {

    return 0;
}
