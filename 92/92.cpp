#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p1 = NULL;
        ListNode* p2 = head;
        ListNode* p3 = p2->next;
        int cnt = 1;
        for (; cnt < m; cnt++) {
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
        }
        ListNode* p4 = p2;
        for (int i = m; i < n; i++) {
            p4 = p4->next;
        }

        if (m >= 2)
            p1->next = p4;  // m >= 2
        p2->next = p4->next;
        for (; cnt < n; ) {
            p1 = p2;
            p2 = p3;
            p3 = p3->next;
            cnt++;
            p2->next = p1;
        }
        
        if (m >= 2)
            return head;
        else
            return p2;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
    ListNode *head = new ListNode(vec[0]);
    ListNode *p = head;
    for (int i = 1; i < vec.size(); i++) {
        p->next = new ListNode(vec[i]);
        p = p->next;
    }
    for (ListNode *p = head; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }
    printf("\n");
    ListNode *reversed = Solution().reverseBetween(head, 1, 1);
    for (ListNode *p = reversed; p != NULL; p = p->next) {
        printf("%d ", p->val);
    }

    return 0;
}
