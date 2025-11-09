//Questions: Merge two sorted arrays without using extra space ---->Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
                                                                    //Output : [-5, -3, -2, 1, 4, 5, 8]
                                                                    //Explanation : The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // i points to last valid element in nums1
        int i = m - 1;

        // j points to last element in nums2
        int j = n - 1;

        // k is the last index of nums1 (including 0 placeholders)
        int k = m + n - 1;

        // Fill nums1 from the end by comparing nums1[i] and nums2[j]
        while (i >= 0 && j >= 0) {
            // Place larger of the two at nums1[k]
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        // If nums2 has remaining elements
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
int main(){
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;
    Solution().merge(nums1, m, nums2, n);
    for (int num : nums1) cout << num << " ";
    return 0;
}
