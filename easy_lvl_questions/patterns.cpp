#include <iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
//   for(int i=1;i<=n;i++){
//     for(int j=0;j<n-i+1;j++){
//         cout<<"* ";
//     }
//     cout<<endl;
//   }
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=n-i+1;j++){
//         cout<<j;
//     }
//     cout<<endl;
//   }

// pyramid pattern:
/*for(int i=0;i<n;i++){
    for(int j=0;j<n-i+1;j++){
        cout<<" ";
    }
    for(int j=0;j<2*i+1;j++){
        cout<<"*";
    }
    for(int j=0;j<n-i+1;j++){
        cout<<" ";
    }
    cout<<endl;
  }*/
  
  
  //reverse pyramid
  /*for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    for(int j=0;j<2*n - 2*i -1;j++){
        cout<<"*";
    }
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    cout<<endl;
  }*/

    /*  1      1
        12    21
        123  321
        12344321
    */
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<j;
    //     }
    //     for(int j=1;j<=n-2*i+4;j++){
    //         cout<<" ";
    //     }
    //     for(int j=i;j>=1;j--){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }
  return 0;
}
