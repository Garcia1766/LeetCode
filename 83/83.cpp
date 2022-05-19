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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        if (cur == NULL)
            return NULL;
        ListNode *next = cur->next;
        while (next != NULL) {
            if (next->val == cur->val) {
                cur->next = next->next;
                ListNode *tmp = next;
                next = next->next;
                delete tmp;
            } else {
                cur = next;
                next = next->next;
            }
        }
        return head;
    }
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

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 6};
    int len = sizeof(arr) / sizeof(int);
    ListNode *head = createList(arr, len);
    printList(head);
    ListNode *head2 = Solution().deleteDuplicates(head);
    printList(head2);
    deleteList(head2);

    return 0;
}
