#include <iostream>
#include <string>
#include <vector>
using namespace::std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lc;
        if (digits.size() == 0) {
            return lc;
        }
        else if (digits.size() == 1) {
            return this->numToLetter(digits[0]);
        }
        else {
            vector<string> sublc = this->letterCombinations(digits.substr(0, digits.size()-1));
            vector<string> newLetter = this->numToLetter(digits[digits.size()-1]);
            for (int i=0; i<sublc.size(); i++) {
                for (int j=0; j<newLetter.size(); j++) {
                    lc.push_back(sublc[i]+newLetter[j]);
                }
            }
            return lc;
        }
    }

    vector<string> numToLetter(char n) {
        vector<string> letters;
        switch (n) {
            case '2': {
                letters.push_back("a");
                letters.push_back("b");
                letters.push_back("c");
                break;
            }
            case '3': {
                letters.push_back("d");
                letters.push_back("e");
                letters.push_back("f");
                break;
            }
            case '4': {
                letters.push_back("g");
                letters.push_back("h");
                letters.push_back("i");
                break;
            }
            case '5': {
                letters.push_back("j");
                letters.push_back("k");
                letters.push_back("l");
                break;
            }
            case '6': {
                letters.push_back("m");
                letters.push_back("n");
                letters.push_back("o");
                break;
            }
            case '7': {
                letters.push_back("p");
                letters.push_back("q");
                letters.push_back("r");
                letters.push_back("s");
                break;
            }
            case '8': {
                letters.push_back("t");
                letters.push_back("u");
                letters.push_back("v");
                break;
            }
            case '9': {
                letters.push_back("w");
                letters.push_back("x");
                letters.push_back("y");
                letters.push_back("z");
                break;
            }
        }
        return letters;
    }
};

int main() {
    Solution sol;
    string s("23");
    vector<string> lc;

    lc = sol.letterCombinations(s);

    for (int i=0; i<lc.size(); i++) {
        cout << lc[i] << ' ';
    }
    cout << endl;

    return 0;
}