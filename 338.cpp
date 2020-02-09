#include <vector>
using namespace::std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int i=0, l = res.size();
        while (res.size() <= num) {
            res.push_back(res[i] + 1);
            i++;
            if (i == l) {
                l *= 2;
                i = 0;
            }
        }

        return res;
    }
};