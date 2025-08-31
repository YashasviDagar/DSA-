#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> brute(vector<vector<int>> &arr, int n,int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int x = 0; x < n; x++)
                {
                    arr[x][j] = -1;
                }
                for (int y = 0; y < m; y++)
                {
                    arr[i][y] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j]=0;
            }
        }
    }
    return arr;
}

vector<vector<int>> better(vector<vector<int>> &arr, int n,int m){
    int row[n]={0};
    int col[m]={0};//tc->(2nm) sc->O(n+m)
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<m ; j++){
        if(arr[i][j]==0){
            row[i]=1;
            col[j]=1;
        }
      }
    }
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<m ; j++){
        if(row[i] || col[j]){
            arr[i][j]=0;
        }
      }
    }
    return arr;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    brute(arr, n,m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}