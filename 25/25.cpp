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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k==1) return head;
        ListNode *dummyHead = new ListNode(-1, head);

        ListNode *p = dummyHead;
        while (p->next) {
            ListNode *node1 = p->next;
            ListNode *node2 = p;
            for (int i = 0; i < k; i++) {
                node2 = node2->next;
                if (!node2) return dummyHead->next;
            }
            ListNode *nxt = node2->next;
            p->next = node2;
            ListNode *cur = node1->next;
            node1->next = nxt;
            // reverse from cur to node2
            ListNode *pre = node1;
            while (pre != node2) {
                ListNode *post = cur->next;
                cur->next = pre;
                pre = cur;
                cur = post;
            }
            p = node1;
        }
        return dummyHead->next;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {1,2,3,4,5}, k = 5;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    ListNode *head2 = Solution().reverseKGroup(l1, k);
    printList(head2);
    deleteList(head2);

    return 0;
}
