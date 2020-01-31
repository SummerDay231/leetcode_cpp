#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        char p;
        bool isPrefix;
        if (strs.size() == 0) 
            return prefix;
        for (int i=0; i<strs[0].size(); i++) {
            p = strs[0][i];
            isPrefix = true;
            for (int j=1; j<strs.size(); j++) {
                if (strs[j][i] != p) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix)
                prefix += p;
            else 
                break;
        }

        return prefix;
    }
};

int main() {
    vector<string> a;
    string inStr;
    Solution sol;

    for (int i=0; i<3; i++) {
        cin >> inStr;
        a.push_back(inStr);
    }

    cout << sol.longestCommonPrefix(a) << endl;

    return 0;
}