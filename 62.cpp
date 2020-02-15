#include <iostream>
using namespace::std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        rec = new int[m * n];
        rec[0*n + 0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i+j == 0) {
                    continue;
                }
                else if (i == 0) {
                    rec[i*n + j] = rec[i*n + (j-1)];
                }
                else if (j == 0) {
                    rec[i*n + j] = rec[(i-1)*n + j];
                }
                else {
                    rec[i*n + j] = rec[i*n + (j-1)] + rec[(i-1)*n + j];
                }
            }
        }
        return rec[(m-1)*n + (n-1)];
    }

    int *rec;
};