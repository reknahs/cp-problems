#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;
const int MAXN = 200005;
ll factorial[MAXN], inv[MAXN];

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while(exp > 0) {
        if(exp%2 == 1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp /= 2;
    }
    return res;
}

ll modinverse(ll n) {
    return power(n, MOD-2);
}

void compute() {
    factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
    inv[MAXN-1] = modinverse(factorial[MAXN-1]);
    for(int i = MAXN-2; i >= 1; i--) {
        inv[i] = (inv[i+1]*(i+1))%MOD;
    }
}

ll choose(int n, int k) {
    if(k < 0 || k > n) return 0;
    return factorial[n]*inv[k]%MOD*inv[n-k]%MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> sums(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> sums[i];
    }
    vector<int> counts(30, -1);
    for(int i = n; i >= 1; i--) {
        ll subtract = 0;
        for(int j = 0; j < 30; j++) {
            if(counts[j] != -1) {
                ll ways = choose(counts[j], i);
                ll bit = (1LL << j)%MOD;
                subtract = (subtract+ways*bit)%MOD;
            }
        }
        ll left = (sums[i]-subtract+MOD)%MOD;
        for(int j = 0; j < 30; j++) {
            if(counts[j] == -1 && ((left >> j) & 1)) {
                counts[j] = i;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        int num = 0;
        for(int j = 0; j < 30; j++) {
            if(counts[j] < 1) continue;
            num += 1<<j;
            counts[j]--;
        }
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    compute();

    int t;
    cin >> t;
    while(t--) solve();
}
