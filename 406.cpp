#include <vector>
#include <algorithm>
#include <iostream>
using namespace::std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<int> newQueue;
        int l = people.size();
        for (int i=0; i<l; i++) {
            newQueue.push_back(people[i][0]*1100 + people[i][1]);
        }
        sort(newQueue.begin(), newQueue.end());
        vector<vector<int>> reQueue(l, vector<int> (2, 0));
        bool *exist = new bool[l];
        for (int i=0; i<l; i++) {
            exist[i] = false;
        }

        for (int i=0; i<l; i++) {
            int h = newQueue[i] / 1100, k = newQueue[i] % 1100;
            int count = -1, pos = -1;
            do {
                pos++;
                //cout << pos << ' ';
                if (exist[pos]==false || reQueue[pos][0] >= h) {
                    count++;
                }
            } while (count < k);
            //cout << endl;
            reQueue[pos] = vector<int>{h, k};
            exist[pos] = true;
        }
        return reQueue;
    }
};

void output(vector<vector<int>> &a) {
    for (vector<vector<int>>::iterator it=a.begin(); it!=a.end(); it++) {
        cout << (*it)[0] << ' ' << (*it)[1] << endl;
    }
};

int main() {
    vector<vector<int>> a, b;
    a.push_back(vector<int>{7, 0});
    a.push_back(vector<int>{4, 4});
    a.push_back(vector<int>{7, 1});
    a.push_back(vector<int>{5, 0});
    a.push_back(vector<int>{6, 1});
    a.push_back(vector<int>{5, 2});
    Solution sol;

    b = sol.reconstructQueue(a);

    output(b);
    
    return 0;
}