#include <vector>
using namespace::std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int r = 0, l = nums.size();
        if (l == 0) {
            return 0;
        }
        m = new int[l];
        for (int i=0; i<l; i++) {
            m[i] = -1;
        }
        return maxMoney(nums, 0);
    }
    int maxMoney(vector<int> &nums, int r) {
        if (this->m[r] != -1) {
            return this->m[r];
        }

        int l = nums.size();
        if (l - r == 1) {
            this->m[r] = nums[l - 1];
            return this->m[r];
        }
        else if (l - r == 2) {
            this->m[r] = nums[l-1] > nums[l-2] ? nums[l-1] : nums[l-2];
            return this->m[r];
        }
        else {
            int a = maxMoney(nums, r+1), b = nums[r] + maxMoney(nums, r+2);
            this->m[r] = a > b ? a : b;
            return this->m[r];
        }
    }

    int *m;
};