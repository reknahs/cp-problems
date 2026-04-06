#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int BITS = 30;
const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0;
    for(int j = 0; j < BITS; j++) {
        vector<ll> prefix1(n+1, 0);
        vector<pair<ll, ll>> sums(n+1, {0, 0});
        for(int i = 0; i < n; i++) {
            prefix1[i+1] = (prefix1[i]+(((1<<j)&arr[i]) != 0))%2;
            sums[i+1].first = sums[i].first;
            sums[i+1].second = sums[i].second;
            if(prefix1[i+1]) {
                sums[i+1].first += (i+1);
            }
            else {
                sums[i+1].second += (i+1);
            }
        }
        vector<ll> prefix2(n+1, 0);
        for(int i = 0; i < n; i++) {
            prefix2[i+1] = prefix2[i]+prefix1[i+1];
        }
        for(int i = 0; i < n; i++) {
            if(!prefix1[i+1]) {
                ans = (ans+((1<<j)*((prefix2[i]*(i+1)-sums[i].first)%MOD))%MOD)%MOD;
            }
            else {
                ans = (ans+(1<<j)*((((i+1-prefix2[i])*(i+1)-sums[i].second))%MOD)%MOD)%MOD;
            }
        }
    }
    cout << ans;
}
