#include <bits/stdc++.h>
using namespace std;
int opti(long long n){
    int low=1,high=n;
    int ans=1;
    while(low<=high){
        long long mid = (low+high)/2;
        if(mid*mid<=n){
            low=mid+1;
            ans=mid;
        }else high=mid-1;
    }
    return ans;
}
int main(){
    long long n;
    cin>>n;
    cout<<opti(n);
  return 0;
}