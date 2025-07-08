#include <bits/stdc++.h>
using namespace std;
set<int> find_union(vector<int>& arr1, vector<int>& arr2,int n,int m){
    set<int> u;
    for(int i=0 ; i<n ; i++){
      u.insert(arr1[i]);
    }
    for(int i=0 ; i<m ; i++){
      u.insert(arr2[i]);
    }
    return u;
}
vector<int> with_pointer(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    int i = 0, j = 0;
    vector<int> temp;
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (temp.empty() || temp.back() != arr1[i]) { // always check empty() condition first.. bcz if temp is empty it shows runtime error
                temp.push_back(arr1[i]);
            }
            i++;// increments should happen regardless of the case..
        } else if (arr2[j] < arr1[i]) {
            if (temp.empty() || temp.back() != arr2[j]) {
                temp.push_back(arr2[j]);
            }
            j++;
        } else { // arr1[i] == arr2[j]
            if (temp.empty() || temp.back() != arr1[i]) {
                temp.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    while (i < n) {
        if (temp.empty() || temp.back() != arr1[i]) {
            temp.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m) {
        if (temp.empty() || temp.back() != arr2[j]) {
            temp.push_back(arr2[j]);
        }
        j++;
    }

    return temp;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<int> arr1(n);
  vector<int> arr2(m);
  for(int i=0 ; i<n ; i++){
    cin>>arr1[i];
  }
  for(int i=0 ; i<m ; i++){
    cin>>arr2[i];
  }
//   set<int> uni = find_union(arr1,arr2,n,m);
//   for(auto it: uni){
//     cout<<it<<" ";
//   }
vector<int> uni=with_pointer(arr1,arr2,n,m);
for(auto it: uni){
    cout<<it<<" ";
}
  return 0;
}