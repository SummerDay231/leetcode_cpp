#include <iostream>
#include <string>
using namespace::std;

class Solution {
public:
    string intToRoman(int num) {
        int quotient, divisor = 1000;
        char c5, c1, c10;
        string romanNum;
        while (num != 0) {
            quotient = num / divisor;
            if (quotient == 0) {
                divisor /= 10;
                continue;
            }
            if (divisor == 1000) {
                c5 = ' ';
                c1 = 'M';
                c10 = ' ';
            }
            else if (divisor == 100) {
                c5 = 'D';
                c1 = 'C';
                c10 = 'M';
            }
            else if (divisor == 10) {
                c5 = 'L';
                c1 = 'X';
                c10 = 'C';
            }
            else if (divisor == 1) {
                c5 = 'V';
                c1 = 'I';
                c10 = 'X';
            }
            else {
                break;
            }
            
            if (quotient == 9) {
                romanNum += c1;
                romanNum += c10; 
            }
            else if (9 > quotient && quotient > 5) {
                romanNum += c5;
                for (int i=0; i<quotient-5; i++) {
                    romanNum += c1;
                }
            }
            else if (quotient == 5) {
                romanNum += c5;
            }
            else if (quotient == 4) {
                romanNum += c1;
                romanNum += c5;
            }
            else {
                for (int i=0; i<quotient; i++) {
                    romanNum += c1;
                }
            }

            num %= divisor;
            divisor /= 10;
        }

        return romanNum;
    }
};

int main() {
    Solution sol;
    int n;
    
    cin >> n;
    cout << sol.intToRoman(n) << endl;

    return 0;
}