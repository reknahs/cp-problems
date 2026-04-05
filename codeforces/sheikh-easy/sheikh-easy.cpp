#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, q;
vector<ll> prefix_sum(100005, 0);
vector<ll> prefix_xor(100005, 0);;

vector<ll> get_best_val(int range) {
    ll best = -1, l = -1, r = -1;
    for(int i = 0; i+range <= n; i++) {
        ll val = (prefix_sum[i+range]-prefix_sum[i])-(prefix_xor[i+range]^prefix_xor[i]);
        if(val > best) {
            best = val;
            l = i;
            r = i+range;
        }
    }
    return {best, l+1, r};
}

void solve() {
    cin >> n >> q;
    vector<int> array(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        prefix_sum[i+1] = prefix_sum[i]+array[i];
        prefix_xor[i+1] = prefix_xor[i]^array[i];
    }
    int li, ri;
    cin >> li >> ri;
    ll desired = get_best_val(n)[0];
    int l = 1, r = n;
    pair<int, int> ans = {1, n};
    while(l <= r) {
        int mid = (l+r)/2;
        const vector<ll> &result = get_best_val(mid);
        if(result[0] == desired) {
            ans = {result[1], result[2]};
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans.first << " " << ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}
