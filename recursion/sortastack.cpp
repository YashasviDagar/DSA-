//Question: Sort a stack using recursion.
#include <bits/stdc++.h>
using namespace std;
void insertSorted(stack<int> &st, int x) {
    // base case: stack empty or top ≤ x --> just push
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int topVal = st.top();
    st.pop();
    //insert x into the smaller stack
    //here is x is smaller than the top ele then ele is popped.. then it again calls the same function to check that the next ele is less than or equal to the x provided if greater it pops it again and process carries on!
    insertSorted(st, x);

    // put the removed element back
    st.push(topVal);
}
void sortStack(stack<int> &st) {
    // base case: empty stack is already sorted
    if (st.empty()) return;
    int topVal = st.top();
    st.pop();
    sortStack(st);
    //insert current element at correct position
    insertSorted(st, topVal);
}

int main() {
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    sortStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
