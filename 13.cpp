#include <iostream>
#include <string>
#include <vector>
using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0, temp = 0;
        vector<int> romanNum;
        for (int i=0; i<s.size(); i++) {
            romanNum.push_back(this->charToNum(s[i]));
        }
        for (int i=s.size()-1; i>=0; i--) {
            if (romanNum[i] >= temp) {
                num += romanNum[i];
            }
            else {
                num -= romanNum[i];
            }
            temp = romanNum[i];
        }

        return num;
    }

    int charToNum(char c) {
        int num;
        if (c == 'I')
            num = 1;
        else if (c == 'V')
            num = 5;
        else if (c == 'X') 
            num = 10;
        else if (c == 'L') 
            num = 50;
        else if (c == 'C') 
            num = 100;
        else if (c == 'D') 
            num = 500;
        else if (c == 'M') 
            num = 1000;

        return num;
    }
};

int main() {
    Solution sol;
    string s("MMXI");

    cout << sol.romanToInt(s) << endl;

    return 0;
}