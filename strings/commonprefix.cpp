#include <bits/stdc++.h>
using namespace std;
string find2(vector<string> str){
    if(str.empty()) return "";
    string pre = str[0];
    int prelen = pre.length();
    for(int i=1 ; i<str.size() ; i++){
        string s=str[i];
        while(prelen>s.length() || pre!=s.substr(0,prelen)){
            prelen--;
            if(prelen==0) return "";
            pre=pre.substr(0,prelen);
        }
    }
    return pre;
}
string find(vector<string> str){
    string ans="";
    sort(str.begin(),str.end());
    string first = str[0],last=str[str.size()-1];
    for(int i=0 ; i<min(first.size(),last.size()) ; i++){
        if(first[i]!=last[i]) return ans;
        else ans+=first[i];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
  vector<string> str(n);
  for(int i=0 ; i<n ; i++){
    cin>>str[i];
  }
//   cout<<find(str);
  cout<<find2(str);
  return 0;
}