#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> c(candidates);
        sort(c.begin(), c.end());
        return cbSum(c, 0, target);
    }

private:
    vector<vector<int> > cbSum(vector<int> &candidates, int left, int target) {
        vector<vector<int> > result;

        for (int i=left; i<candidates.size(); i++) {
            if (candidates[i] == target) {
                vector<int> t{candidates[i]};
                result.push_back(t);
                break;
            }
            else if (target < candidates[i]) {
                break;
            }
            else {
                vector<vector<int> > temp = cbSum(candidates, i, target-candidates[i]);
                for (vector<vector<int>>::iterator it = temp.begin(); it != temp.end(); it++) {
                    vector<int> t(*it);
                    t.push_back(candidates[i]);
                    result.push_back(t);
                }
            }
        }
        /*for (vector<vector<int>>::iterator it1=result.begin(); it1!=result.end(); it1++) {
            for (vector<int>::iterator it2=it1->begin(); it2!=it1->end(); it2++) {
                cout << *it2 << ' ';
            }
            cout << endl;
        }*/
        return result;
    }
};

int main() {
    vector<int> a{2, 3 ,5};
    int t = 8;
    Solution sol;
    vector<vector<int> > s = sol.combinationSum(a, t);

    for (vector<vector<int>>::iterator it1=s.begin(); it1!=s.end(); it1++) {
        for (vector<int>::iterator it2=it1->begin(); it2!=it1->end(); it2++) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }

    return 0;
}