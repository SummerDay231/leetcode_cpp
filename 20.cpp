#include <iostream>
#include <stack>
#include <string>
using namespace::std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(' || s[i]=='[' || s[i] == '{') {
                brackets.push(s[i]);
            }
            else if (s[i] == ')') {
                if (!brackets.empty() && brackets.top() == '(') {
                    brackets.pop();
                }
                else
                    return false;
            }
            else if (s[i] == ']') {
                if (!brackets.empty() && brackets.top() == '[') {
                    brackets.pop();
                }   
                else
                    return false;
            }
            else if (s[i] == '}') {
                if (!brackets.empty() && brackets.top() == '{') {
                    brackets.pop();
                }
                else
                    return false;
            }
        }
        return brackets.empty();
    }
};

int main() {
    string s;
    Solution sol;

    cin >> s;
    cout << sol.isValid(s) << endl;

    return 0;
}