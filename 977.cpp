#include <vector>
using namespace::std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int divide;
        vector<int> newA;
        if (A.size() == 0) {
            return newA;
        }
        for (divide=0; divide<A.size()-1; divide++) {
            if (A[divide]<=0 && A[divide+1]>=0) {
                break;
            }
            else if (A[divide] > 0) {
                break;
            }
        }
        int neg = divide, pos = divide + 1;
        while (neg >= 0 && pos < A.size()) {
            if (A[neg]*A[neg] > A[pos]*A[pos]) {
                newA.push_back(A[pos]*A[pos]);
                pos++;
            }
            else {
                newA.push_back(A[neg]*A[neg]);
                neg--;
            }
        }
        while (neg >= 0) {
            newA.push_back(A[neg]*A[neg]);
            neg--;
        }
        while (pos < A.size()) {
            newA.push_back(A[pos]*A[pos]);
            pos++;
        }

        return newA;
    }
};