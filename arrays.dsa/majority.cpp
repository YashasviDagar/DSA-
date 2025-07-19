#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {
    int n = v.size();
    int cnt = 0;
    int cnt1 = 0;
    int el; 
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]){
            cnt++;
        }
        else cnt--;
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}