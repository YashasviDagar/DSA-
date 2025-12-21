#include <bits/stdc++.h>
using namespace std;
bool optimal(string s,string y){
    if(s.length()!=y.length()) return false;
    string doubled = s + s;//tc->O(n)
    return doubled.find(y)!=string::npos;//string::npos means not found!
}
bool check(string s,string y){
    if(s.length()!=y.length()) return false;
    int n = s.length();
    int count=0;//this bcz its shifts the string array by one so it ensures it is shifted n times if required!
    while(count<n){
        char t=s[n-1];//tc->O(n2)
        for(int i=n-1;i>0;--i){
            s[i]=s[i-1];
        }
        s[0]=t;
        if(s==y) return true;
        count++;
    }
    return false;
}
int main(){
  string s;
  string y;
  cin>>s>>y;
//   cout<<check(s,y);
  cout<<optimal(s,y);
  return 0;
}