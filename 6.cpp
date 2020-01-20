#include <iostream>
#include <string>
#include <vector>
using namespace::std;

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size(), row = 0;
        if (numRows == 1 || size < numRows) {
            return s;
        }
        bool goDown = false;
        string zStr;
        vector<string> rowStr(numRows);
        
        for (int i=0; i<size; i++) {
            rowStr[row].append(s,i,1);
            if (row == 0 || row == numRows - 1) {
                goDown = !goDown;
            }
            if (goDown) {
                row++;
            }
            else {
                row--;
            }
        }

        for (int i=0; i<numRows; i++) {
            zStr.append(rowStr[i]);
        }

        return zStr;
    }
};

int main() {
    Solution sol;
    string s("LEETCODEISHIRING");

    cout << sol.convert(s, 3) << endl;

    return 0;
}