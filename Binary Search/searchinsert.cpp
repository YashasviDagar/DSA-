#include <bits/stdc++.h>
using namespace std;
int search_insert(vector<int>& arr,int target){
    int n=arr.size();
    int low=0,high=n-1,j=0;
    int index=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            high=mid-1;
            index=mid;
        }else low=mid+1;
    }
    cout<<index<<endl;
    if(index!=n){
        for(int i=0 ; i<n ; i++){
          if(arr[i]<target && arr[i+1]>target){
            j=i+1;
            arr.insert(arr.begin()+i+1,target);
          }
        }
    }
}
int main(){
  int n,target;
  cin>>n>>target;    
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  search_insert(arr,target);
  for(int i=0 ; i<arr.size() ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}