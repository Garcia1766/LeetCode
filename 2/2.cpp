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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res_head = new ListNode(0);
        ListNode *res = new ListNode(0);
        res->next = res_head;
        int carry = 0;
        while (l1 && l2) {
            int t = l1->val + l2->val + carry;
            res->next->val = t % 10;
            carry = t / 10;
            l1 = l1->next;
            l2 = l2->next;
            res->next->next = new ListNode(0);
            res = res->next;
        }
        while (l1) {
            int t = l1->val + carry;
            res->next->val = t % 10;
            carry = t / 10;
            l1 = l1->next;
            res->next->next = new ListNode(0);
            res = res->next;
        }
        while (l2) {
            int t = l2->val + carry;
            res->next->val = t % 10;
            carry = t / 10;
            l2 = l2->next;
            res->next->next = new ListNode(0);
            res = res->next;
        }
        res->next->val = carry;
        if (res->next->val == 0)
            res->next = NULL;
        return res_head;
    }
};

int main() {
    int arr1[] = {9,9,9,9,9,9,9}, arr2[] = {9,9,9,9};
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
