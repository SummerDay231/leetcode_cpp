#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int leftBound = 0;
        int maxSize = 0;
        for (int i=1; i<s.size(); i++) {
            for (int j=i-1; j>=leftBound; j--) {
                bool flag = false;
                if (s[i] == s[j]) {
                    maxSize = maxSize > i-leftBound ? maxSize : i-leftBound;
                    leftBound = j + 1;
                    flag = true;
                }
                if (flag) {
                    break;
                }
            }
        }
        maxSize = maxSize > s.size()-leftBound ? maxSize : s.size()-leftBound;

        return maxSize;
    }
};

int main() {
    string s("cdd");
    Solution sol;

    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}