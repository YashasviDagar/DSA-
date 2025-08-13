// Question: Two sum-> for a given target the two indexes of array will give the sum equals to the target!
#include <bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& arr,int target){
    //tc->O(N^2)
    for(int i=0 ; i<arr.size() ; i++){
      for(int j=i+1 ; j<arr.size() ; j++){
        if(arr[j]==target-arr[i]);
        return {j,i};//with i,j answer vector is reversed!
      }
    }
    return {};
}

vector<int> optimal(vector<int>& arr,int target){
    //tc->O(n)+O(nlogn)
    int n = arr.size();
    sort(arr.begin(),arr.end());
    int left=0, right=n-1;
    while(left<=right){
        int sum = arr[left]+arr[right];
        if(sum==target) return {left,right};//this array index will be of the sorted array index!
        else if(sum<target) left++;
        else right--;
    }
    return {};
}

vector<int> withMap(vector<int>& arr,int target){
    //tc->O(N)
    unordered_map<int,int> mp;
    for(int i=0 ; i<arr.size() ; i++){
        int remain = target - arr[i];//with {i,remain} ans is reversed! bcz when the first iteration the map doesn't have the remaining value present. therefore in the further iteration when the remain is found it returns that value that'swhy i is return last, so that the the compliment of(i,remain) gives the answer ie. (remain,i)*
        if(mp.find(remain)!=mp.end()){ return {mp[remain],i}; }
        mp[arr[i]]=i;
    }
    return {};
}

int main(){
  int n;
  cout<<"Array size\n";
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  int target;
  cout<<"Enter sum target\n";
  cin>>target;
//   vector<int> ans = brute(arr,target);
//   vector<int> ans = optimal(arr,target);
  vector<int> ans = withMap(arr,target);
  for(int i=0 ; i<ans.size() ; i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}