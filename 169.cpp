#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m = nums[0], n = 1;

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == m) {
                n++;
            }
            else {
                n--;
                if (n == 0) {
                    m = nums[i];
                    n = 1;
                }
            }
        }

        return m;
    }
};