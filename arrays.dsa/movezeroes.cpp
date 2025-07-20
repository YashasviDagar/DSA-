#include <bits/stdc++.h>
using namespace std;
int bruteforce(vector<int>& arr,int n){
    vector<int> temp;
    for(int i=0 ; i<n ; i++){
      if(arr[i]!=0){
        temp.push_back(arr[i]);
      }
    }
    for(int i=0 ; i<temp.size() ; i++){
      arr[i]=temp[i];
    }
    for(int i=temp.size() ; i<n ; i++){
      arr[i]=0;
    }
}

int optimal(vector<int>& arr,int n){
    int j=0;
    for(int i=0 ; i<n ; i++){
      if(arr[i]==0){
        j=i;
        break;
      }
    }
    int i=j+1;
    while(i<n){
      if(arr[i]!=0){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j++;
        i++;
      }else i++;
    }
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
//   bruteforce(arr,n);
optimal(arr,n);
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}