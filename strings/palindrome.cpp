#include <bits/stdc++.h>
using namespace std;
bool checker(string s){
    int st=0,end=s.length()-1;
    while(st<=end){
        if(s[st++]!=s[end--]) return false;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<checker(s);
  return 0;
}