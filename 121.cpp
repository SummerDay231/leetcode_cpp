#include <vector>
using namespace::std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int maxPrice = prices[prices.size()-1], maxP = 0;
        for (int i=prices.size()-2; i>=0; i--) {
            if (prices[i] > maxPrice) {
                maxPrice = prices[i];
                continue;
            }
            if (maxPrice - prices[i] > maxP) {
                maxP = maxPrice - prices[i];
            }
        }

        return maxP;
    }
};