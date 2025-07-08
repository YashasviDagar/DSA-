#include <bits/stdc++.h>
using namespace std;
string find(string s){
    string result=" ";
    int n = stoi(s);
    if(n%2==0){
        while(n>0){
            int d=n%10;
            if(d%2!=0){
                result+=to_string(d);
                result+=" ";
            }
            n/=10;
        }
    }else{
        result+=to_string(n);
    }
    return result;
}
int main(){
  string s;
  cin>>s;
  cout<<find(s);
  return 0;
}