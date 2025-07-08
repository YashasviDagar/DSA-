#include <bits/stdc++.h>
using namespace std;
/*int brute method:
 for(i=1->m){
 if(f(i,n)==m) return 1=i;
 else if(f(i,n)>m) break;
 return -1;}
 */
int func(int mid,int n,int m){
    long long ans=1;
    for(int i=1 ; i<=n ; i++){
      ans = ans*mid;
      if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}
int ans(int n,int m){
    int low=1,high=m;
    while(low<=high){
        int mid = (low+high)/2;
        long long power = func(mid,n,m);
        if(power==1) return mid;
        else if(power==0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
// int check(int n,int m){
//     int low=1,high=m;
//     while(low<=high){
//         int mid = (low+high)/2;
//         long long power = 1;
//         for(int i=1 ; i<=n ; i++){
//           power*=mid;
//           if(power>m) break;
//         }
//         if(power==m) return mid;
//         else if(power<m) low=mid+1;
//         else high=mid-1;
//     }
//     return -1;
// }
int main(){
  int n,m;
  cin>>n>>m;
 cout<<ans(n,m);
//   cout<<check(n,m);
  return 0;
}