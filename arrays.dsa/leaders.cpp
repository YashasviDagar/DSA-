//Question: Leaders in an array is called as the numbers who is greater than the total sum of all the right elements!

#include <bits/stdc++.h>
using namespace std;
int cal_leader(vector<int> &arr,int n){
    vector<int> temp;
    for(int i=0 ; i<n ; i++){
        int sum=0;
      for(int j=i+1 ; j<n ; j++){
        sum+=arr[j];
      }
      if(arr[i]>sum) temp.push_back(arr[i]);
    }
    for(int i=0 ; i<temp.size() ; i++){
      cout<<temp[i]<<" ";
    }
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  cal_leader(arr,n);
  return 0;
}