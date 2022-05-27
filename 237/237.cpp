#include<iostream>
#include<vector>

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
    void deleteNode(ListNode* node) {
        if (!node) return;
        if (!node->next) {
            delete node;
            node = NULL;
            return;
        }
        node->val = node->next->val;
        ListNode *nxt = node->next;
        node->next = nxt->next;
        delete nxt;
        return;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {4,5,1,9}, val = 1;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    ListNode *p = l1;
    for (int i = 0; i < 2; i++) p = p->next;
    Solution().deleteNode(p);
    printList(l1);
    deleteList(l1);

    return 0;
}
