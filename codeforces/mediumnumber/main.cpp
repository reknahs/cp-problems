#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    vector<int> abc(3);
    for(int i = 0; i < 3; i++) cin >> abc[i];
    sort(abc.begin(), abc.end());
    cout << abc[1] << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
