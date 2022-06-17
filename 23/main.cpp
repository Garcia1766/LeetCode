#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(int arr[], int len) {
    if (len == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]);
    ListNode *cur = head;
    for (int i = 1; i < len; i++) {
        cur->next = new ListNode(arr[i]);
        cur  = cur->next;
    }
    return head;
}

void printList(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
}

void deleteList(ListNode *head) {
    ListNode *cur = head;
    for (; cur != NULL; ) {
        ListNode *del = cur;
        cur = cur->next;
        delete del;
    }
}

ListNode* reverseList(ListNode *head) {
    ListNode *pre = NULL, *cur = head;
    while (cur) {
        ListNode *post = cur->next;
        cur->next = pre;
        pre = cur;
        cur = post;
    }
    return pre;
}

bool cmp(ListNode* l1, ListNode* l2) {  // greater
    return l1->val > l2->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(cmp);
        ListNode* dummyHead = new ListNode();
        ListNode* cur = dummyHead;
        for (auto l : lists) if (l) pq.push(l);
        while (!pq.empty()) {
            cur->next = new ListNode(pq.top()->val);
            cur = cur->next;
            if (pq.top()->next) pq.push(pq.top()->next);
            pq.pop();
        }
        return dummyHead->next;
    }
};

int main() {
    int arr1[] = {1,4,5}, arr2[] = {1,3,4}, arr3[] = {2,6};
    int* arr[] = {arr1, arr2, arr3};
    int len[] = {3, 3, 2};
    vector<ListNode*> lists;
    for (int i = 0; i < 3; i++) {
        lists.push_back(createList(arr[i], len[i]));
        printList(lists[i]);
    }
    ListNode *head2 = Solution().mergeKLists(lists);
    printList(head2);
    deleteList(head2);

    return 0;
}
