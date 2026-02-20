#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int n;
vector<ll> barns;
vector<ll> prefix;

ll score(ll a, ll b, ll y) {
    ll left_barns = upper_bound(barns.begin(), barns.end(), y) - barns.begin();
    ll left = (y * left_barns - prefix[left_barns]) * a;
    ll right = (prefix[n] - prefix[left_barns] - y * (n - left_barns)) * b;
    return left + right;
}

int main() {
    cin >> n;
    barns.resize(n);
    prefix.resize(n+1);
    for(int i = 0; i < n; i++) {
        cin >> barns[i];
    }
    sort(barns.begin(), barns.end());
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1]+barns[i-1];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;

        ll l = 0, r = 1000001;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (score(a, b, mid) <= score(a, b, mid + 1)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << score(a, b, l) << endl;
    }
}
