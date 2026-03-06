#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int t, n, m;

vector<ll> prefix;

ll psum(int l, int r) {
    if(l > r) return 0;
    return prefix[r+1] - prefix[l];
}

int solve() {
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] %= m;
    }
    sort(arr.begin(), arr.end());
    vector<ll> total;
    for(int i = 0; i < n; i++) total.push_back(arr[i]);
    for(int i = 0; i < n; i++) total.push_back(arr[i]+m);
    prefix.resize(2*n+1, 0);
    for(int i = 0; i < 2*n; i++) prefix[i+1] = prefix[i]+total[i];

    ll best = INT64_MAX;
    for(int i = 0; i < 2*n; i++) {
        ll mini = total[i] - m/2;
        ll maxi = total[i] + (m-1)/2;
        if(mini < 0 || maxi >= 2*m) continue;

        int l = lower_bound(total.begin(), total.end(), mini) - total.begin();
        int r = upper_bound(total.begin(), total.end(), maxi) - total.begin() - 1;
        ll add = total[i]*(i-l) - psum(l, i-1);
        ll subtract = psum(i+1, r) - total[i]*(r-i);
        best = min(best, add+subtract);
    }
    cout << best << endl;
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
