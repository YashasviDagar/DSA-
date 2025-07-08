#include <bits/stdc++.h>
using namespace std;
int withoutduplicates(vector<int>& arr,int n, int target){
    int low=0,high=n-1;
    while(low<=high){  //#tc-> O(log2(N))
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]<arr[mid]){
            if(arr[low]<=target && target</**=**/arr[mid]){//dont complicate things^
                high=mid-1;
            }else low=mid+1;
        }else if(arr[low]>arr[mid]){
            if(arr[mid]</**=**/target && target<=arr[high]){
                low=mid+1;
            }else high = mid-1;
        }
    }
    return -1;
}
bool withduplicates(vector<int>& arr,int n,int target){
    int low=0,high=n-1;
    while(low<=high){  //#tc-> O(log2(N)) ^avg
        int mid=(low+high)/2;//tc->O(n/2) where with dups u have to almost shrink most of the array!
        if(arr[mid]==target) return true;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low+=1;
            high-=1;
            continue;
        }
        if(arr[low]<arr[mid]){
            if(arr[low]<=target && target</**=**/arr[mid]){
                high=mid-1;
            }else low=mid+1;
        }else if(arr[low]>arr[mid]){
            if(arr[mid]</**=**/target && target<=arr[high]){
                low=mid+1;
            }else high = mid-1;
        }
    }
    return false;
}
int main(){
    int n;
    int target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    // cout<<withoutduplicates(arr,n,target);
    cout<<withduplicates(arr,n,target);
  return 0;
}