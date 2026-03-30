#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    ll n;
    cin >> n;
    ll arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll maxgap = 0;
    ll maximum = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maximum) {
            maximum = arr[i];
        }
        else {
            maxgap = max(maxgap, maximum-arr[i]);
        }
    }
    if(maxgap == 0) cout << 0 << endl;
    else cout << floor(log2(maxgap))+1 << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
