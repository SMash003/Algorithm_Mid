#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        vec.push_back({start, end});
    }
    sort(vec.begin(), vec.end(), compare);

    int take = 1;
    int end = vec[0][1];

    for(int i = 1; i<n; i++){
        if(vec[i][0] >= end){
            take++;
            end = vec[i][1];
        }
    }

    cout << take << endl;
}
