#include <bits/stdc++.h>
using namespace std;
int finddays(vector<int> &weights,int capa){
    int day = 1;
    int load = 0;//the amount to be carried once
    int n = weights.size();
    for(int i=0 ; i<n ; i++){
        if(load + weights[i] > capa){//prev load + the current load of the day!
            day+=1;//here when the load+wt is exceeded wrt capacity then the day is increase as a particular capaity shipment is packed!
            load = weights[i];//reassigned the load to current weight. Bcz when load+wt exceeds so for the next day the current load will the load next in the weights arrays. so from there onwards new load is carried.
        }else load+=weights[i];
    }
    return day;
}
int brute(vector<int> &weights,int days){
    int maxi = *max_element(weights.begin(),weights.end());//finds max ele in the array:
    int sum = accumulate(weights.begin(),weights.end(),0);//find the sum of the array
    for(int i=maxi ; i<=sum ; i++){//start from the max to sum bcz the answer range is in btw:
        if(finddays(weights,i)==days){//here i is the day capacity which is sum of the elements in array with different permutations and combinations:
            return i;
        }
    }
    return -1;
}
int optimal(vector<int>& weights,int days){//O(N * log(sum(weights[]) - max(weights[]) + 1))
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid = (low+high)/2;
        int noOfDays = finddays(weights,mid);
        if(noOfDays<=days){
            high=mid-1;//here the range is max to sum so with the per and combinations the sums after the mid value is removed: As its obv they will take more days.
        }else low=mid+1;
    }
    return low;
}
int main(){
  int n;
  cin>>n;
  vector<int> weights(n);
  for(int i=0 ; i<n ; i++){
    cin>>weights[i];
  }
  int day;
  cin>>day;
  int cap = optimal(weights,day);
  cout<<cap;
  return 0;
}