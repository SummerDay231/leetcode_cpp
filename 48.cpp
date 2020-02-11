#include <vector>
using namespace::std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; i++) {
            rotateRound(matrix, i);
        }
    }

    void rotateRound(vector<vector<int>> &matrix, int r) {
        int n = matrix.size();
        for (int i=0; r+i<n-r-1; i++) {
            int x1 = r, y1 = r + i;
            int x2 = r + i, y2 = n - 1 - r;
            int x3 = n - 1 - r, y3 = n - 1 - r - i;
            int x4 = n - 1 - r - i, y4 = r;
            int temp;
            temp = matrix[x2][y2];
            matrix[x2][y2] = matrix[x1][y1]; // 1 -> 2
            matrix[x1][y1] = matrix[x3][y3];
            matrix[x3][y3] = temp; // 2 -> 3
            temp = matrix[x4][y4];
            matrix[x4][y4] = matrix[x1][y1]; // 3 -> 4
            matrix[x1][y1] = temp; // 4 -> 1
        }
    }
};