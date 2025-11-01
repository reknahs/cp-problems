#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long cakes[n];
    for(int i = 0; i < n; i++) {
        cin >> cakes[i];
    }
    long long prefix[n+1];
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + cakes[i];
    }
    long long bessie = LLONG_MAX;
    for(int i = 0; i < n/2; i++) {
        bessie = min(bessie, prefix[n/2+i+1]-prefix[i]);
    }
    long long elsie = prefix[n] - bessie;
    cout << bessie << " " << elsie << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        solve();
    }
}


