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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return NULL;
        ListNode *h1, *cur1, *nxt1, *h2, *cur2, *nxt2, *p;
        p = new ListNode();
        h1 = h2 = p->next = head;
        bool flag1 = false, flag2 = false;
        int bigger = 0;
        if (head->val < x)
            bigger = 2;
        else
            bigger = 1;
        while (p->next != NULL) {
            if (p->next->val < x) {
                if (!flag1) {
                    h1 = p->next;
                    flag1 = true;
                }
            } else {
                if (!flag2) {
                    h2 = p->next;
                    flag2 = true;
                }
            }
            if (flag1 && flag2)
                break;
            p = p->next;
        }  // p->next == max(h1, h2)
        if (p->next == NULL)
            return head;
        printf("h1, h2, p, p->next, bigger = %d, %d, %d, %d, %d\n",
            h1->val, h2->val, p->val, p->next->val, bigger);
        if (bigger == 2) {
            cur1 = p;
            cur2 = h2;
            nxt1 = nxt2 = p->next->next;
        } else {
            cur2 = p;
            cur1 = h1;
            nxt1 = nxt2 = p->next->next;
        }  // initialization finished
        // if (nxt1 != NULL)
        //     printf("h1, h2, cur1, cur2, nxt1, nxt2, p, p->next = %d, %d, %d, %d, %d, %d, %d, %d\n",
        //         h1->val, h2->val, cur1->val, cur2->val, nxt1->val, nxt2->val, p->val, p->next->val);
        // else
        //     printf("h1, h2, cur1, cur2, nxt1, nxt2, p, p->next = %d, %d, %d, %d, NULL, NULL, %d, %d\n",
        //         h1->val, h2->val, cur1->val, cur2->val, p->val, p->next->val);
        
        while (p->next != NULL) {
            p = p->next;  // p == the furthest explored
            if (p->next != NULL) {
                if (p->next->val < x) {
                    cur1->next = nxt1;
                    cur1 = nxt1;
                    nxt1 = nxt1->next;
                    nxt2 = nxt1;
                } else {
                    cur2->next = nxt2;
                    cur2 = nxt2;
                    nxt2 = nxt2->next;
                    nxt1 = nxt2;
                }
            }
            // if (nxt1 != NULL)
            //     printf("h1, h2, cur1, cur2, nxt1, nxt2, p, p->next = %d, %d, %d, %d, %d, %d, %d, %d\n",
            //         h1->val, h2->val, cur1->val, cur2->val, nxt1->val, nxt2->val, p->val, p->next->val);
            // else {
            //     if (p->next != NULL)
            //         printf("h1, h2, cur1, cur2, nxt1, nxt2, p, p->next = %d, %d, %d, %d, NULL, NULL, %d, %d\n",
            //             h1->val, h2->val, cur1->val, cur2->val, p->val, p->next->val);
            //     else
            //         printf("h1, h2, cur1, cur2, nxt1, nxt2, p, p->next = %d, %d, %d, %d, NULL, NULL, %d, NULL\n",
            //             h1->val, h2->val, cur1->val, cur2->val, p->val);
            // }
        }
        cur1->next = h2;
        cur2->next = NULL;
        return h1;
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
    int arr[] = {1,4,3,2,5,2}, x = 3;
    // int arr[] = {2, 1}, x = 2;
    int len = sizeof(arr) / sizeof(int);
    ListNode *head = createList(arr, len);
    printList(head);
    ListNode *head2 = Solution().partition(head, x);
    printList(head2);
    deleteList(head2);

    return 0;
}
