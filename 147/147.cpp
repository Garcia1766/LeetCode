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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummyHead = new ListNode(-5001, head);

        ListNode *tail = dummyHead->next;
        while (tail->next) {
            ListNode *cur = tail->next;
            ListNode *nxt = cur->next;  // might be NULL
            ListNode *p = dummyHead;
            for (; p != tail; p = p->next) {
                if (cur->val < p->next->val) {
                    cur->next = p->next;
                    p->next = cur;
                    tail->next = nxt;
                    break;
                }
            }
            if (p == tail) {
                tail = tail->next;
            }
        }
        ListNode *retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {}, val = 1;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    ListNode *head2 = Solution().insertionSortList(l1);
    printList(head2);
    deleteList(head2);

    return 0;
}
