#include <bits/stdc++.h>
using namespace std;
int iterative(vector<int>&arr,int n,int target){
    int low=0,high=n-1;
    while(low<=high){
    int mid = (low+high)/2;//every time mid will change!
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) low = mid+1; //left side array is of no use.
        else if(target<arr[mid]) high = mid-1;//right side array is of no use.
    }
    return -1; //this is case where high>low and target is not present in the array!
}
int recursive(vector<int>& arr,int low,int high,int target){
  if(low>high) return -1;
  int mid = (low+high)/2;           //   Time complexity-> O(log2(N))
  if(arr[mid]==target) return mid;
  else if(target>arr[mid]) recursive(arr,mid+1,high,target);
  else if(target<arr[mid]) recursive(arr,low,mid-1,target);
}
int main(){
  int n,target;
  cin>>n>>target;    //#OVERFLOW!# case if u are sure u take 0 and INT_MAX then take mid as low +   (high - low)/2
  vector<int> arr(n);// as if low and high are at same pos then it won't be 2*INT_MAX it will be (INT_MAX - INT_MAX) /2
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  // if(iterative(arr,n,target)!=-1) cout<<"Found";
  // else cout<<"Not Found";
  if(recursive(arr,0,n-1,target)!=-1) cout<<"Found";
  else cout<<"Not Found";
  return 0;
}