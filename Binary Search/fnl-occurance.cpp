#include <bits/stdc++.h>
using namespace std;
int first_occur(vector<int>& arr,int target){
    int n=arr.size();
    int low=0, high =n-1;
    int first = -1;
    while(low<=high){
        int mid=(low+high)/2;  //log(n)
        if(arr[mid]==target){
            first=mid;
            high=mid-1;//agar ye second value h toh sorted m ek aur hona chahiye target which can be the first occurance!
        }else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return first;
}
int last_occur(vector<int>& arr, int target){
    int n=arr.size();
    int low=0, high =n-1;
    int last = -1;        //log(n)
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            last=mid;
            low=mid+1;
        }else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return last;
}
int main(){
  int n;    // 2*log(n) is the time complexity so if first is -1 dont call last occurance
  cin>>n;
  int target;
  cin>>target;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  int f=first_occur(arr,target);
  if(f==-1) cout<<"{-1,-1}";
  else cout<<"{"<<f<<","<<last_occur(arr,target)<<"}";
  
  return 0;
}