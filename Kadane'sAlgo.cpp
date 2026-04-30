#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Number of elements: " << endl;
    cin >> n;

    vector<int> vec(n);
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    int currSum = vec[0], maxSum = vec[0];
    for(int i=0; i<n; i++){
        currSum = max(vec[i], currSum + vec[i]);
        maxSum = max(maxSum, currSum);
    }

    cout << "Maximum subarray sum: " << maxSum;
    return 0;
}