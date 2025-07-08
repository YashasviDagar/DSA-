#include <bits/stdc++.h>
using namespace std;
int consecutive_ones(vector<int>& arr, int n){
    if(n==0) return 0;
    int flag=0;
    for(int j=0 ; j<n ; j++){
        if(arr[j]==0) flag=0;
        else flag=1;
        break;
    }
    if(flag==0) return 0;
    int m=0,i=0;
    int max=INT_MIN;
    while(i<n){
        if(arr[i]==0){
            m=0;
        }
        if(arr[i]!=0){
            if(arr[i]==1){
                if(m>=max){
                    m++;
                    max=m;
                }else m++;
            }
        } 
        i++;
    }
    return max;
}

int findMaxConsecutiveOnes(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        int maximum=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                cnt++;
                maximum=max(maximum,cnt);
            }else cnt=0;
        }
        return maximum;
}
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  cout<<consecutive_ones(arr,n);
  return 0;
}