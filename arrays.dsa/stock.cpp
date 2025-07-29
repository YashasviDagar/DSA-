#include <bits/stdc++.h>
using namespace std;
int brute(vector<int> &arr,int n){
    int maxi = 0;
    for(int i=0 ; i<n ; i++){
      for(int j=i+1 ; j<n ; j++){
        if(arr[j]>arr[i]){
            maxi = max(arr[j]-arr[i],maxi);
        }
      }
    }
    return maxi;
}
int maxprofit(vector<int> &arr,int n){
    int maxi = 0;
    int mini = INT_MAX;
    for(int i=0 ; i<n ; i++){
      mini = min(arr[i],mini);
      maxi = max(maxi,arr[i]-mini);
    }
    return maxi;
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  int ans = maxprofit(arr,n);
  cout<<ans;
  return 0;
}