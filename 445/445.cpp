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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1 = reverseList(l1);
        ListNode *h2 = reverseList(l2);
        printList(h1);
        printList(h2);

        ListNode *res_head = new ListNode(0);
        ListNode *res = res_head;
        int carry = 0;
        while (h1 || h2) {
            int x1 = h1 ? h1->val : 0;
            int x2 = h2 ? h2->val : 0;
            int t = x1 + x2 + carry;
            carry = t / 10;
            res->next = new ListNode(t % 10);
            res = res->next;
            if (h1) h1 = h1->next;
            if (h2) h2 = h2->next;
        }
        if (carry > 0)
            res->next = new ListNode(carry);
        
        return reverseList(res_head->next);
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {0}, arr2[] = {0};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    ListNode *l2 = createList(arr2, len2);
    printList(l1);
    printList(l2);
    ListNode *head2 = Solution().addTwoNumbers(l1, l2);
    printList(head2);
    deleteList(head2);

    return 0;
}
