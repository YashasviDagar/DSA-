//Q: Sort the array of One's Two's and Zeroes:
#include <bits/stdc++.h>
using namespace std;

int better(vector<int>& arr){
    int cnt0=0,cnt1=0,cnt2=0;//tc->O(N)+O(N)
    int n = arr.size();
    for(int i=0 ; i<n ; i++){
      if(arr[i]==0) cnt0++;
      if(arr[i]==1) cnt1++;
      if(arr[i]==2) cnt2++;
    }
    for(int i=0 ; i<cnt0 ; i++){
      arr[i]=0;
    }
    for(int i=cnt0 ; i<cnt0+cnt1 ; i++){
      arr[i]=1;
    }
    for(int i=cnt0+cnt1 ; i<n ; i++){
      arr[i]=2;
    }
}

int optimal(vector<int>& arr){
  int n = arr.size();//tc->O(N)
  int low = 0;
  int mid = 0;//here low mid and high is the number representing the index in the array that's why 0,0,n-1 and arr[0]:
  int high = n-1;
  while(mid<high){
    for(int i=0 ; i<n ; i++){
      if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        mid++;
        low++;
      }else if(arr[mid]==1){
        mid++;
      }else{
        swap(arr[mid],arr[high]);
        high--;
      }
    }
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  optimal(arr);
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}