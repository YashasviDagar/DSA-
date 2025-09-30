//Question: Next permuatation of a given array is that finding all combination of array then arrange them in an order then find the greatest one just after the input array:
#include <bits/stdc++.h>
using namespace std;
vector<int> nextPermutation(vector<int>& arr) {
    int n=arr.size();
    int ind = -1;
    for(int i=n-2 ; i>=0 ; i--){
      if(arr[i]<arr[i+1]){
        ind=i;//finding the breaking point in the array from the back
        break;
      }
    }
    if(ind==-1) reverse(arr.begin(),arr.end());//edge case when the permutation is the largest one so entire array is reversed: i.e the first permutation
    for(int i=n-1 ; i>=ind ; i--){
      if(arr[i]>arr[ind]){
        swap(arr[i],arr[ind]);
        break;
      }
    }
    reverse(arr.begin()+ind+1,arr.end());//now make the remaining array the smallest one by reverseing it.
    return arr;
}
int main(){
   vector<int> arr={1,2,3};
    nextPermutation(arr);
    for(auto x:arr) cout<<x<<" ";
   return 0;
}