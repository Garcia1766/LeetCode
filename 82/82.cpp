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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode *dummyHead = new ListNode(-101, head);
        ListNode *cur = dummyHead;
        int delVal = -101;
        while (cur->next) {
            if (cur->next->next && cur->next->val == cur->next->next->val) {
                delVal = cur->next->val;
                while (cur->next->next && cur->next->next->val == delVal) {
                    ListNode *delNode = cur->next->next;
                    cur->next->next = cur->next->next->next;
                    delete delNode;
                }
                ListNode *delNode = cur->next;
                cur->next = cur->next->next;
                delete delNode;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {1,1,1,2,2,3}, val = 1;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    ListNode *head2 = Solution().deleteDuplicates(l1);
    printList(head2);
    deleteList(head2);

    return 0;
}
