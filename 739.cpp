#include <vector>
#include <stack>
using namespace::std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<vector<int>> temp;
        vector<int> answer(T.size(), 0);
        temp.push(vector<int> {T[0], 0});
        for (int i=1; i<T.size(); i++) {
            while (!temp.empty() && temp.top()[0] < T[i]) {
                answer[temp.top()[1]] = i - temp.top()[1];
                temp.pop();
            }
            temp.push(vector<int>{T[i], i});
        }
        while (!temp.empty()) {
            answer[temp.top()[1]] == 0;
            temp.pop();
        }
        return answer;
    }
};