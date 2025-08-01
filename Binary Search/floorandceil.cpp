#include <bits/stdc++.h>
using namespace std;
//The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).
int floor(vector<int>& arr, int target){
    int n=arr.size();
    int low=0,high=n-1;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            low=mid+1;
            index=mid;
        }else{
            high=mid-1;
        }
    }
    cout<<"Floor "<<arr[index]<<" ";
}

//The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).
int ceil(vector<int>& arr,int target){
    floor(arr,target);
    int n=arr.size();
    int low=0, high=n-1;
    int index=-1;
    while(low<=high){
        int mid=(low+high)/2;  
        if(arr[mid]>=target){
            high=mid-1;
            index=mid;
        }
        else{
            low=mid+1; 
        }              
    }                  
    cout<<"Ceil "<<arr[index]<<endl;
}

int main(){
  int n,target;
  cin>>n>>target;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
  ceil(arr,target);
  return 0;
}