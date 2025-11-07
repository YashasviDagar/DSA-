//Question: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // Vector to store final merged intervals
        vector<vector<int>> merged;
        // Traverse each interval
        for (auto interval : intervals) {
            //if merged is empty or current interval does not overlap!
            if (merged.empty() || merged.back()[1] < interval[0]) {
                //Add current interval as a new non-overlapping block1
                merged.push_back(interval);
            } else {
                //merge by extending the end time
                merged.back()[1] = max(
                    merged.back()[1],
                    interval[1]
                );
            }
        }
        return merged;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals={
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };
    vector<vector<int>> result = sol.merge(intervals);
    for (auto v : result){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}