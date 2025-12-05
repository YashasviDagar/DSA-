//Question: Find the maximum depth of the parantheses of a string.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public://tc->O(N)
    // Method to compute maximum depth of parentheses
    int maxDepth(string s) {
        int p = 0;  
        int ans = 0;
        for (char x : s) {
            // Increase depth on open parenthesis
            if (x == '(') p++;
            // Decrease depth on close parenthesis
            else if (x == ')') p--;
            // Update maximum depth encountered
            ans = max(ans, p);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    int result = sol.maxDepth(s);
    cout << "Max Depth: " << result << endl;
    return 0;
}