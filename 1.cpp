#include <iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> a(2);
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    a[0] = i;
                    a[1] = j;
                    return a;
                }
            }
        }
        return a;
    };
};

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> b(a, a+5);
    int t = 5;
    Solution s;
    cout << s.twoSum(b, t)[1] << endl;
}