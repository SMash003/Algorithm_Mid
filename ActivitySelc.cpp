#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end; 
}

int main() {
    int n;
    cout << "Number of activities: " << endl;
    cin >> n;

    vector<Activity> vec(n);

    cout << "Start and end of activities: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> vec[i].start >> vec[i].end;
    }

    sort(vec.begin(), vec.end(), compare);

    int take = 1;
    int lastEnd = vec[0].end;

    for (int i = 1; i < n; i++) {
        if (vec[i].start >= lastEnd) {
            take++;
            lastEnd = vec[i].end;
        }
    }

    cout << take << endl;
}