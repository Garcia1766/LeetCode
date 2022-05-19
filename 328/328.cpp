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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode *odd_head = new ListNode();
        ListNode *even_head = new ListNode();
        ListNode *odd = odd_head, *even = even_head;
        int pos = 1;
        while (head != NULL) {
            if (pos % 2) {  // odd
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
            pos++;
        }
        odd->next = even_head->next;
        even->next = NULL;
        return odd_head->next;
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
    int arr[] = {2,1,3,5,6,4,7};
    int len = sizeof(arr) / sizeof(int);
    ListNode *head = createList(arr, len);
    printList(head);
    ListNode *head2 = Solution().oddEvenList(head);
    printList(head2);
    deleteList(head2);

    return 0;
}
