#include <iostream>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slowPtr = head, *fastPtr = head, *loopStart = head;
        do {
            if (fastPtr == NULL || fastPtr->next == NULL) {
                return NULL;
            }
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        } while (slowPtr != fastPtr);
        
        while (slowPtr != loopStart) {
            slowPtr = slowPtr->next;
            loopStart = loopStart->next;
        }
        return loopStart;        
    }
};