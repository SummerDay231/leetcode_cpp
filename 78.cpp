#include <vector>
using namespace::std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> a;
        res.push_back(a);
        for (int i=0; i<nums.size(); i++) {
            int l = res.size();
            for (int j=0; j<l; j++) {
                vector<int> b(res[j]);
                b.push_back(nums[i]);
                res.push_back(b);
            }
        }

        return res;
    }
};