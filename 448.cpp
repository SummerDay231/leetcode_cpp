#include <vector>
#include <iostream>
using namespace::std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            int j = nums[i] -1, temp;
            while (j != -1 && nums[j] != 0) {
                temp = nums[j];
                nums[j] = 0;
                j = temp - 1;
            }
        }

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                res.push_back(i+1);
            }
        }

        return res;
    }
};

int main() {
    int a[] = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> b(a, a+8);
    Solution sol;

    vector<int> c = sol.findDisappearedNumbers(b);

    for(int i=0; i<c.size(); i++) {
        cout << c[i] << ' ';
    }

    cout << endl;

    return 0;
}