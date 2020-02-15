#include <iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle1(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        do {
            if (fastPtr == NULL || fastPtr->next == NULL) {
                return false;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        } while (slowPtr != fastPtr);
        
        return true;
    }

    bool hasCycle2(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head;
        do {
            if (fastPtr == NULL || fastPtr->next == NULL || head->next->next == NULL) {
                return false;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next->next;
        } while (slowPtr != fastPtr && slowPtr != fastPtr->next);
        
        return true;
    }
};