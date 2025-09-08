//Question: Find the smallest element in the sorted rotated array!
#include <bits/stdc++.h>
using namespace std;
int brute(vector<int>& arr,int n){
    int a=INT_MAX, index=-1;
    for(int i=0 ; i<n ; i++){
      if(arr[i]<a){
        a=arr[i];
        index=i;
      }
    }
    return index;
}

int optimal(vector<int>& arr,int n){
  int low=0, high=n-1,mini=INT_MAX,index=-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(arr[low]<=arr[high]){
      if(arr[low]<mini){
        index=low;
        mini=arr[low];
        break;
      }
    }
    if(arr[low]<=arr[mid]){
      if(arr[low]<mini){
        index=low;//its basically finding the minimum element in the rotated array and then using its index to tell the answer!
        mini=arr[low];
      }
      low=mid+1;//now since the left array is sorted and the ans will be the smallest element in the left array.. to check another smallest we have to go the right side or if its not present that means the ans from the left half is the smallest element present.. so low=mid+1:
    }else{
      if(arr[mid]<mini){
        index=mid;
        mini=arr[mid];
      }
      high=mid-1;
    }
  }
  return index;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    // cout<<brute(arr,n);
    cout<<optimal(arr,n);
  return 0;
}