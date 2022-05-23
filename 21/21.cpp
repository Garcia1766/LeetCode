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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return list1 ? list1 : list2;
        ListNode *dummyHead = new ListNode(-101);
        dummyHead->next = list1->val <= list2->val ? list1 : list2;
        ListNode *tail = dummyHead->next;
        ListNode *other = list1->val <= list2->val ? list2 : list1;
        while(tail->next) {
            if (other->val < tail->next->val) {
                ListNode *tmp = other;
                other = tail->next;
                tail->next = tmp;
                tail = tail->next;
            } else {
                tail = tail->next;
            }
        }
        tail->next = other;
        return dummyHead->next;
    }
};

int main() {
    // int arr1[] = {1,2,4}, arr2[] = {1,3,4};
    int arr1[] = {}, arr2[] = {};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    ListNode *l1 = createList(arr1, len1);
    ListNode *l2 = createList(arr2, len2);
    printList(l1);
    printList(l2);
    ListNode *head2 = Solution().mergeTwoLists(l1, l2);
    printList(head2);
    deleteList(head2);

    return 0;
}
