#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& arr,int n){
    int low=0,high=n-1,mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;//#tc-> O(lof2(N))
        if(arr[low]<=arr[high]){
            mini=min(mini,arr[low]);
            break;//if the whole array is sorted.
        }
        if(arr[low]<=arr[mid]){
            mini=min(mini,arr[low]);
            low=mid+1;                //checking right or left sorted!
        }else if(arr[low]>=arr[mid]){
            mini=min(mini,arr[mid]);
            high=mid-1;
        }
    }
    return mini;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    cout<<find(arr,n);
  return 0;
}