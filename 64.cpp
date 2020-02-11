#include <vector>
using namespace::std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) {
            vector<int> temp(n, -1);
            this->rec.push_back(temp);
        }
        this->rec[0][0] = grid[0][0];
        return minPS(grid, m-1, n-1);
    }

    int minPS(vector<vector<int>> &grid, int x, int y) {
        if (this->rec[x][y] != -1) {
            return this->rec[x][y];
        }
        else {
            if (x == 0) {
                this->rec[x][y] = grid[x][y] + minPS(grid, x, y-1);
            }
            else if (y == 0) {
                this->rec[x][y] = grid[x][y] + minPS(grid, x-1, y);
            }
            else {
                int left = minPS(grid, x, y-1), up = minPS(grid, x-1, y);
                this->rec[x][y] = grid[x][y] + (left < up ? left : up);
            }
            return this->rec[x][y];
        }
    }

    vector<vector<int>> rec;
};