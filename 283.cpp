#include <vector>
using namespace::std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nextNonZero = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                if (nums[nextNonZero] == 0) {
                    nums[nextNonZero] = nums[i];
                    nums[i] = 0;
                }
            }
            if (nums[nextNonZero] != 0) {
                nextNonZero++;
            }
        }
    }
};