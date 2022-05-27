#include<iostream>
#include<vector>
#include<cassert>

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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n >= 1);
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; i++) {
            assert(q);
            q = q->next;
        }
        while (q) {
            p = p->next;
            q = q->next;
        }
        ListNode *del = p->next;
        p->next = del->next;
        delete del;

        return dummyHead->next;
    }
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        assert(n >= 1);
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *p = head;
        int sz = 0;
        while (p) {
            p = p->next;
            sz++;
        }
        p = dummyHead;
        for (int i = 0; i < sz - n; i++) {
            p = p->next;
        }
        ListNode *del = p->next;
        p->next = del->next;
        delete del;

        return dummyHead->next;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {1,2,3,4,5}, n = 2;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    ListNode *head2 = Solution().removeNthFromEnd2(l1, n);
    printList(head2);
    deleteList(head2);

    return 0;
}
