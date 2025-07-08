#include <bits/stdc++.h>
using namespace std;
int brute(vector<int>& arr,int n){
    int index=-1;
    vector<int> ind;
    if(arr[0]>arr[1]) ind.push_back(0);
    for(int i=1 ; i<n-1 ; i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            ind.push_back(i);
            index=i;
        }
    }
    if(arr[n-2]<arr[n-1]) ind.push_back(n-1);
    cout<<"peak at indexes ";
    for(auto it: ind){
        cout<<it<<" ";
    }
}
int optimal(vector<int>& arr,int n){
    int low=1,high=n-2;
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;  //first if the edge cases are true these will run otherwise we go to the binary search!
    if(arr[n-1]>arr[n-2]) return n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) return mid;
        if(arr[mid]>arr[mid-1]) low=mid+1; // for these i dont need the extra for loops like in brute force method to calc the peak..
        else high=mid-1;                   // its just reduce the search index and then the only mid value will be returned.
    }
    
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    // brute(arr,n);
    cout<<optimal(arr,n);
  return 0;
}