// Question: Rearrange the array in alternating positive and negative items?
#include <bits/stdc++.h>
using namespace std;

vector<int> brute(vector<int>& arr,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0 ; i<n ; i++){
      if(arr[i]>0) pos.push_back(arr[i]);
      else neg.push_back(arr[i]);
    }
    for(int i=0 ; i<n/2 ; i++){
      arr[2*i]=pos[i];
      arr[2*i+1]=neg[i];
    }
    return arr;
}

vector<int> optimal(vector<int> &arr, int n)
{
    vector<int> ans(n);
    int i = 0, j = 1;
    for (int k = 0; k < n; k++)
    {
        if (arr[k] > 0)
        {
            ans[i] = arr[k];
            i += 2;
        }
        else
        {
            ans[j] = arr[k];
            j += 2;
        }
    }
    return ans;
}

//Q: Other variety where the number of pos and negs are not equal:
vector<int> other_type(vector<int> A, int n)
{                    // tc->O(2N)
    vector<int> pos; // sc->(n/2+n/2)
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
            pos.push_back(A[i]);
        else
            neg.push_back(A[i]);
    }

    if (pos.size() < neg.size())
    {
        for (int i = 0; i < pos.size(); i++)
        {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2; // this because we dont now how many extra neg elements are there but know that the equal pos and neg will be there then after that there will be more neg elememts so it makes sure that twice of pos i.e pos+(neg which are equal to pos):
        for (int i = pos.size(); i < neg.size(); i++)
        {
            A[index] = neg[i];
            index++;
        }
    }

    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            A[2 * i] = pos[i];
            A[2 * i + 1] = neg[i];
        }
        // Fill the remaining positives at the end of the array.
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {

            A[index] = pos[i];
            index++;
        }
    }
    return A;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = brute(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}