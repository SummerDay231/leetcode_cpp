#include <iostream>
#include <vector>
using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pos1 = l1, *pos2 = l2, *l3, *rear = NULL, *p;
        int c0, c1, temp;
        c0 = 0;
        while ((pos1!=NULL)&&(pos2!=NULL)) {
            temp = pos1->val + pos2->val + c0;
            c0 = temp / 10;
            c1 = temp % 10;
            p = new ListNode(c1);
            if (rear == NULL) {
                l3 = p;
                rear = p;
            }
            else {
                rear->next = p;
                rear = p;
            }
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        while (pos1 != NULL) {
            temp = pos1->val + c0;
            c0 = temp / 10;
            c1 = temp % 10;
            p = new ListNode(c1);
            if (rear == NULL) {
                l3 = p;
                rear = p;
            }
            else {
                rear->next = p;
                rear = p;
            }
            pos1 = pos1->next;
        }
        while (pos2 != NULL) {
            temp = pos2->val + c0;
            c0 = temp / 10;
            c1 = temp % 10;
            p = new ListNode(c1);
            if (rear == NULL) {
                l3 = p;
                rear = p;
            }
            else {
                rear->next = p;
                rear = p;
            }
            pos1 = pos2->next;
        }

        if (c0 != 0) {
            ListNode *p = new ListNode(c0);
            rear->next = p;
            rear = p;
        }

        return l3;
    }
};

int main() {
    ListNode *l1=NULL, *l2=NULL, *l3;
    int a[] = {9, 9, 9, 1}, b[] = {9, 9, 8};
    for (int i=0; i<4; i++) {
        ListNode *p = new ListNode(a[i]);
        p->next = l1;
        l1 = p;
    }
    for (int i=0; i<3; i++) {
        ListNode *p = new ListNode(b[i]);
        p->next = l2;
        l2 = p;
    }
    
    Solution s;
    l3 = s.addTwoNumbers(l1, l2);
    for (ListNode *p=l3; p!=NULL; p=p->next) {
        cout << p->val;
    }
    cout << endl;

    return 0;
}