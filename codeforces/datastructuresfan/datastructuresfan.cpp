#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int prefix[n+1];
    for(int i = 0; i < n; i++) cin >> arr[i];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1]^arr[i-1];
    string s;
    cin >> s;
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') zero ^= arr[i];
        if(s[i] == '1') one ^= arr[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int l, r;
            cin >> l >> r;
            one ^= prefix[r]^prefix[l-1];
            zero ^= prefix[r]^prefix[l-1];
        }
        else if(tp == 2){
            int g;
            cin >> g;
            cout << (g ? one : zero) << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
