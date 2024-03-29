#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    stack<NestedInteger> stk;
    void flattenList(vector<NestedInteger> nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            stk.push(nestedList[i]);
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }
    
    int next() {
        if (!hasNext()) return NULL;
        int ret = stk.top().getInteger();
        stk.pop();
        return ret;
    }
    
    bool hasNext() {
        while (!stk.empty() && !stk.top().isInteger()) {
            NestedInteger ni = stk.top();
            stk.pop();
            flattenList(ni.getList());
        }
        return !stk.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    return 0;
}