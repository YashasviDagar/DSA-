#include <bits/stdc++.h>
using namespace std;
int me_brute(vector<int> &arr, int n, long long k){
    int maxsub = 0;
    for(int j=0 ; j<n ; j++){
        int sum = 0; //used to reset the value of sum for each j:
        for (int i = j; i < n; i++){
            sum += arr[i];  //tc->O(n^2)
            if (sum == k){
                int len=i-j+1;
                maxsub = max(maxsub,len);//no break to ensure that the longest subarr again can also be found at one j:
            }
        }
    }
    return maxsub;
}
int better(vector<int>& arr, int n, long long k){
    map<long long,int> prefixsum;//[2,0,0,3] hash store 2,2 means 2 sum till index 2: its correct but longest id 0,0,3 and not just 3 bcz x-k is 2,0,0
    long long sum=0;//sc->O(n)
    int maxlen=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i];
        if(sum==k){//if unordered map *worst case*tc->O(n.1)==O(n^2) ordered mapp tc-> O(nlog(n))
            maxlen= max(maxlen,i+1);
        }//this is optimal code for array of positives and NEGATIVES
        long long rem=sum-k;
        if(prefixsum.find(rem) != prefixsum.end()){
            int len=i-prefixsum[rem];
            maxlen=max(maxlen,len);
        }
        if(prefixsum.find(sum) == prefixsum.end()) prefixsum[sum]=i;
        //this fixs by above problem of existing of zeroes! 
    }
    return maxlen;
}
int optimal(vector<int>& arr,int n,long long k){
    int left=0,right=0,maxlen=0;//tc at worst case O(2n) bcz second while is added to the first while: sc->O(1):
    long long sum=arr[0];
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxlen;
}
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << me_brute(arr, n, k);
    cout<<better(arr,n,k);
    // cout<<optimal(arr,n,k);
    return 0;
}