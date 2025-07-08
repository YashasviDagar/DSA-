#include <bits/stdc++.h>
using namespace std;
bool iso(string s,string t){
    if(s.length()!=t.length()) return false;
    unordered_map<char,int> indexs;
    unordered_map<char,int> indext;
    for(int i=0 ; i<s.length() ; i++){
        if(indexs.find(s[i])==indexs.end()){//if not found initially it return to the end iterator 
                                            //thats why it is compared to end() function.
            indexs[s[i]]=i;
        }
        if(indext.find(t[i])==indext.end()){
            indext[t[i]]=i;
        }
        if(indexs[s[i]]!=indext[t[i]]) return false;
    }
    return true;
}
int main(){
  string s,t;
  cin>>s;
  cin>>t;
  cout<<iso(s,t);
  return 0;
}