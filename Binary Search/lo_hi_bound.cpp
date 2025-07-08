#include <bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>& arr,int target){
    int n= arr.size();
    int low=0, high=n-1;
    int index=n;
    while(low<=high){
        int mid=(low+high)/2;  //O(log2(N))
        //maybe or maybe not the answer!
        if(arr[mid]>=target){
            high=mid-1;
            index=mid;
        }
        else{
            low=mid+1; // here when target is greater than mid, so i remove all the ele from mid to low. 
        }              // And search in the direction od mid+1 to high. Untill and unless i cant get a value of arr[mid]>=target 
    }                  // i wont change my index:! 
    cout<<index;
}
int upper_bound(vector<int>& arr,int target){
    int n=arr.size();
    int low=0,high=n-1;
    int index=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            high=mid-1;
            index=mid;
        }else low=mid+1;
    }
    cout<<index;
}
int main(){
  int n,target;
  cin>>n>>target;    
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  lower_bound(arr,target);
//   upper_bound(arr,target);
  return 0;
}