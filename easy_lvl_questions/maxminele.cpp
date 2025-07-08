#include <bits/stdc++.h>
using namespace std;
int frequency(int arr[],int n){
  unordered_map<int,int> map;
  for(int i=0;i<n;i++){// this is for counting the freq of each element.
    map[arr[i]]++;
  }
  int maxele=0, minele=0;
  int max=INT_MIN, min=INT_MAX;
  for(auto it: map){ // yeh map k har ek element ke paas ja rh h. islia har ek freq and element alag alag hoga!.
    int freq=it.second;
    int element=it.first;
    if(freq>max){
      max=freq;
      maxele=element;
    }
    if(freq<min){
      min=freq;
      minele=element;
    }
  }
  cout<<"The maximum frequency element is "<<maxele<<" and the minimum frequency element is "<<minele<<endl;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  frequency(arr,n);
  return 0;
}