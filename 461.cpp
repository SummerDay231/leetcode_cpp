class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y, hDis = 0;

        while (z != 0) {
            hDis += z % 2;
            z = z >> 1;
        }

        return hDis;
    }
};