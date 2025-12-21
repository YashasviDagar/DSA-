#include <bits/stdc++.h>
using namespace std;
string first(string s){
    string result;
    int a=0,b=0;     //tc->O(n)
    int start=0;
    for(int i=0 ; i<s.length() ; i++){
      if(s[i]=='(') a+=1;
      if(s[i]==')') b+=1;
      if(a==b){
        result+=s.substr(start+1,i-start-1);//takes a particular sub string from given string acc. to the index!
        start=i+1;
      }
    }
    return result;
}
string second(string s){
    string result;
    int balance=0;
    for(int i=0 ; i<s.size() ; i++){
        if(s[i] =='('){    //tc->O(n)
            if(balance>0){
                result+=s[i];
            }
            balance++;//it increases almost everytime.
        }else if(s[i]==')'){
            balance--;
            if(balance>0) result+=s[i];
        }
    }
    return result;
}
int main(){
  string s;
  cin>>s;
//   cout<<first(s);
  cout<<second(s);
  return 0;
}