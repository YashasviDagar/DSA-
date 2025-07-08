#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//optimal approach!
int opti(int arr[],int low,int high){
  while(low<=high){
    int temp=arr[high];
    arr[high]=arr[low];
    arr[low]=temp;
    low++;
    high--;
  }
}
int rev(int arr[],int n,int k,int low,int high){
  int d = k%n;
  opti(arr,low,d-1);
  opti(arr,d,high);
  opti(arr,low,high);
}
int with_STL(int arr[], int n, int k){
  int d= k%n;
  reverse(arr,arr+d);   //it goes till (arr+d)-1 last ele not included;
  reverse(arr+d,arr+n);
  reverse(arr,arr+n);
}
int brute_fore(int arr[],int n,int k){
  int d=k%n;
  int temp[d];
  for(int i=0 ; i<n-d ; i++){
    temp[i]=arr[i];
  }
  for(int i=d ; i<n ; i++){
    arr[i-d]=arr[i];
  }
  for(int i=n-d ; i<n ; i++){
    for(int j=0 ; j<d ; j++){
      arr[i]=temp[j];
    }
  }
}
int main(){
  int n;
  int k;
  cin>>n>>k;
  int arr[n];
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  // with_STL(arr,n,k);
  // rev(arr,n,k,0,n-1);
  brute_fore(arr,n,k);
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}