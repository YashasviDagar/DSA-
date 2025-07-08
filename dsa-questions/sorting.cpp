#include <bits/stdc++.h>
using namespace std;
int bubble_sort(int arr[], int n){ 
    for(int i=n-1 ; i>=1 ; i--){        // bcz iss bar last mein ele store kia hai and 0 tk jane ka mtlb ni bcz last ele is alwz sorted.
        int didswap=0;
        for(int j=0 ; j<=i-1 ; j++){    // isme comparision will take place for n-2 times.. where n-1 is number till j can go[0-5] 
        if(arr[j]>arr[j+1]){            //and n-1-1 is bcz we can compare last ele with someone else.
            int temp=arr[j+1];
            arr[j+1]=arr[j];            //O(n^2)
            arr[j]=temp;
            didswap =1;
        }
      }
      if(didswap=0){                    //it is the best case where it is already in sorted order. O(n)
        break;
      }
    }
}
int selection_sort(int arr[], int n){
    for(int i=0 ; i<=n-2 ; i++){
        int min = i; //considering the min element is present at first index only
      for(int j=i+1 ; j<=n-1 ; j++){ // we can take j=i as well but i+1 removes one extra loop of arr[0]<arr[0]!
        if(arr[j]<arr[i]){
            min = j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
      }
    }
}
int insertion_sort(int arr[],int n){
    for(int i=0 ; i<=n-1 ; i++){
      for(int j=i ; j>=1 ; j--){
        if(arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
      }
    }
}
int recur_bubblesort(int arr[],int n){
  if(n<1) return 1;
  for(int i=0 ; i<=n-1 ; i++){
    if (arr[i]>arr[i+1])
    {
      int temp=arr[i+1];
      arr[i+1]=arr[i];
      arr[i]=temp;
    }
  }
  recur_bubblesort(arr,n-1);
}
int recur_insertionsort(int arr[],int a,int n){
  if(a>=n) return 1;
  for(int i=a ; i<=n-1 ; i++){
    for(int j=i;j>=1 ; j--){
      if(arr[j-1]>arr[j]){
        int temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
      }
    }
  }
  recur_insertionsort(arr,a+1,n);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
      cin>>arr[i];
    }
    // selection_sort(arr,n);
    // bubble_sort(arr,n);
    // insertion_sort(arr,n);
    // recur_bubblesort(arr,n);
    recur_insertionsort(arr,0,n);
    for(int i=0 ; i<n ; i++){
      cout<<arr[i]<<" ";
    }
  return 0;
}
