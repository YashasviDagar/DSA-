#include <bits/stdc++.h>
using namespace std;
int remove(int arr[],int n){
  int i=0;                       //this method se hi index aa rhe the.. and it works in the sorted array only!
  for(int j=1 ; j<n ; j++){
    if(arr[j]!=arr[i]){
      arr[i+1]=arr[j];
      i++;
    }
  }
  cout<<"The nuber of unique elements are: "<<i+1<<endl;
}
int left_rotate(int arr[],int n){
  for(int i=0 ; i<=n-2; i++){
    int temp=arr[i+1];
    arr[i+1]=arr[i];
    arr[i]=temp;
  }
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  // remove(arr,n);
  // left_rotate(arr,n);
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}