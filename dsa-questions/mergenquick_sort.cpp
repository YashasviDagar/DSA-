/**#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr,int low,int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;                      //dont forget to increase the value.
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){                   //these while conditions are for the remaining values left. if first while loop turns out to be false.
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low ; i<=high ; i++){
      arr[i]=temp[i-low]; //If low = 3 and high = 6, temp has indices 0, 1, 2, 3 (size->high - low + 1 = 4).
                          //If you use arr[i] = temp[i], you're trying to access temp[i] 
                          //where i is in the range 3 to 6. But temp only has valid indices 0 to 3. This mismatch causes errors!
    }
    
  return 0;
}
int _merge_sort(vector<int> &arr,int low,int high){
    int mid = (low + high) / 2; // or n/2 to (n/2)+1
    if(low>=high) return 1;
    _merge_sort(arr,low,mid);
    _merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    return 0;
} 
int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  // _merge_sort(arr,0,n-1); // cant go till the last index. 
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}**/


//QUICK SORT
#include <bits/stdc++.h>
using namespace std;
int quick(int arr[],int low,int high){
  int pivot=arr[low];
  int i=low;
  int j=high;
    while(i<j){
      while(arr[i]<=pivot && i<=high-1){
        i++;
      }
      while(arr[j]>=pivot && j>=low+1){
        j--;
      }
      if(i<j){
        int temp = arr[j];
        arr[j]=arr[i];
        arr[i]=temp;
      }
    }
    int temp1=arr[j];
    arr[j]=arr[low];
    arr[low]=temp1;
    return j;
}
int quick_sort(int arr[],int low,int high){
    if(low<=high){
      int partition=quick(arr,low,high);
      quick_sort(arr,low,partition-1);
      quick_sort(arr,partition+1,high);
    }
    return 0;
}
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0 ; i<n ; i++){
    cin>>arr[i];
  }
  quick_sort(arr,0,n-1);
  for(int i=0 ; i<n ; i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}