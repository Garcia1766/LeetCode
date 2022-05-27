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

ListNode *getMid(ListNode *head) {  // list点数为2k时，将第k个点的next置NULL，返回第k+1个点；点数为2k+1时，将第k+1个点的next置NULL，返回第k+2个点
    if (!head || !head->next) return head;
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *slow = dummyHead;
    ListNode *fast = dummyHead;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;
    return mid;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        ListNode *mid = getMid(head);
        ListNode *head2 = reverseList(mid);
        ListNode *p = head;
        ListNode *q = head2;
        while (q) {
            if (p->val != q->val) return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};

int main() {
    // int arr1[] = {2,4,3}, arr2[] = {5,6,4};
    int arr1[] = {1,2,3,2,1}, k = 4;
    int len1 = sizeof(arr1) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    printList(l1);
    bool ans = Solution().isPalindrome(l1);
    printf("%d\n", ans);
    // printList(l1);
    deleteList(l1);

    return 0;
}
