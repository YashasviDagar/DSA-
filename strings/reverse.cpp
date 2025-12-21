#include <bits/stdc++.h>
using namespace std;
string swapping(string s){
    int st=0,end=s.length()-1;
    while(st<=end){
        swap(s[st++],s[end--]);
    }
    return s;
}
string reversing(string s){
    reverse(s.begin(),s.end());
    return s;
}
int main(){
  string s;
  cin>>s;
  cout<<swapping(s);
    // cout<<reversing(s);
  return 0;
}