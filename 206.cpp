#include <iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *tail = reLst(head);

        if (head == NULL) {
            return NULL;
        }
        head = tail->next;
        tail->next = NULL;

        return head;
    }
    ListNode* reLst(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *prev = reLst(head->next);
        if (prev != NULL) {
            head->next = prev->next;
            prev->next = head;
        }
        else {
            head->next = head;
        }

        return head;
    }
};