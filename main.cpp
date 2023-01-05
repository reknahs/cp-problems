#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ranges[300][300];

bool correct(int ind, const vector<int> &arr) {
    int mini = INT32_MAX;
    int maxi = -INT32_MAX;
    for(int i = ind; i < n; i++) {
        mini = min(arr[i], mini);
        maxi = max(arr[i], maxi);
        if(maxi-mini != ranges[ind][i-ind]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> ranges[i][j-i];
        }
    }
    vector<int> arr(n, 0);
    for(int i = n-2; i >= 0; i--) {
        arr[i] = arr[i+1]+ranges[i][1];
        if(!correct(i, arr)) {
            arr[i] = arr[i+1]-ranges[i][1];
        }
    }
    for(int i = 0; i < n-1; i++) {
        cout << arr[i] << " ";
    }
    cout << arr[n-1] << endl;
}
