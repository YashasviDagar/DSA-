#include <bits/stdc++.h>
using namespace std;
int hashing(vector<int>& arr,int n){
    int a = arr[0];// the main reason to not use this is because of an arr can have negatives,10^7 so u cant hash it!!
                   // therefore we use map with <long long ,int >
    for(int i=0 ; i<n ; i++){//O(n)
        a=max(a,arr[i]);
    }
    int hash[a]={0};                     //tc->O(3N)  and sc->O(a)space for a hash
    for(int i=0 ; i<n ; i++){//O(n)
      hash[arr[i]]++;
    }
    for(int i=0 ; i<n ; i++){
      if(hash[arr[i]]==1) return arr[i]; //O(n)
    }//this can be change wrt n!
    return -1;
}
int brute(vector<int>& arr,int n){
    for(int i=0 ; i<n ; i++){
      int num=arr[i];
      int cnt=0;
      for(int j=0 ; j<n ; j++){
        if(arr[j]==num) cnt++;
      }
      if(cnt==1) return num;
    }
    return -1;
}
int mapping(vector<int>& arr,int n){
    map<long long,int> mpp;
    for(int i=0 ; i<n ; i++){  //O(NlogM) + O(n/2 + 1){this is the number of element i.e size of map}
      mpp[arr[i]]++;           // M is the size of map.. where m can change
    }
    for(auto it:mpp){
      if(it.second==1) return it.first;
    }
    return -1;
}
int optimal(vector<int>& arr, int n){
    int xorr=0;
    for(int i=0 ; i<n ; i++){ //tc-> O(N) sc->O(1)
      xorr=xorr^arr[i];
    }
    return xorr;
}
int binary(vector<int>& arr,int n){
  if(n==1) return arr[0];
  if(arr[0]!=arr[1]) return arr[0];
  if(arr[n-1]!=arr[n-2]) return arr[n-1];
  int low=1,high=n-2;
  while(low<=high){ //TIME COMPLEXEITY-> O(logN)
    int mid=(low+high)/2;
    if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];
    if(mid%2==1 && arr[mid]==arr[mid-1] || mid%2==0 && arr[mid]==arr[mid+1]){
      low=mid+1;
    }else high=mid-1;
  }
  return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    // cout<<hashing(arr,n);
    // cout<<brute(arr,n);
    // cout<<mapping(arr,n);
    // cout<<optimal(arr,n);
    cout<<binary(arr,n);
    return 0;
}