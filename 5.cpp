#include <iostream>
#include <string>
#include <cstring>
using namespace::std;

class Solution {
public:
    string longestPalindrome(string s) {
        this->size = s.size();
        if (this->size == 0) {
            string res = "";
            return res;
        }
        this->s = s;
        int maxLen = 0, left, len;
        this->tag = new int[1000000]; // 不采用二维数组，一方面是初始化方便，一方面能减少一半的空间 // 取消
        for (int i=0; i<1000000; i++) {
            this->tag[i] = -1;
        }

        for (int i=0; i<this->size; i++) {
            for (int j=i; j<this->size; j++) {
                if (isPalindrome(i, j) == 1) {
                    len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        left = i;
                    }
                }
            }
        }
        
        return s.substr(left, maxLen);
        //return s;
    }

    bool isPalindrome(int i, int j) {
        int pos = i * this->size + j;
        int *tag = this->tag;
        if (tag[pos] == -1) {
            string s = this->s;
            if (j == i) {
                tag[pos] = 1;
            }
            else if (j == i + 1) {
                tag[pos] = s[i]==s[j] ? 1 : 0;
            }
            else if (s[i] != s[j]) {
                tag[pos] = 0;
            }
            else {
                tag[pos] = isPalindrome(i+1, j-1)==1 ? 1 : 0;
            }
        }

        return tag[pos];
    }

    int *tag;
    int size;
    string s;
};

int main() {
    string s("jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx");
    Solution sol;

    
    cout << sol.longestPalindrome(s) << endl;

    return 0;
}