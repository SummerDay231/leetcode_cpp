#include <iostream>

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n, next;
        do {
            slow = subAndSum(slow);
            next = subAndSum(fast);
            fast = subAndSum(next);
            if (next == 1 || fast == 1) {
                return true;
            }
        } while (slow != fast);

        return false;
    }

    int subAndSum(int n) {
        int sum = 0;

        while (n != 0) {
            sum += (n%10) * (n%10);
            n /= 10;
        }

        return sum;
    }
};