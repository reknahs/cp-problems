#include <iostream>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
ll factorial[1000002];
ll inv_factorial[1000002];

// binary exponentiation
ll bexp(ll base, ll exp) {
    if(exp == 1) {
        return base;
    }
    ll ans = bexp(base, exp/2);
    ans = (ans * ans) % MOD;
    if(exp%2 == 1) {
        ans = ans * base % MOD;
    }
    return ans;
}

// combination formula
ll choose(ll num, ll sub) {
    return factorial[num] * inv_factorial[sub] % MOD * inv_factorial[num-sub] % MOD;
}

int main() {
    // compute all factorials
    factorial[0] = 1;
    for(ll i = 1; i < 1000002; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    // compute all inverse factorials
    inv_factorial[1000001] = bexp(factorial[1000001], MOD-2);
    for(ll i = 1000000; i >= 0; i--) {
        inv_factorial[i] = (inv_factorial[i+1] * (i+1)) % MOD;
        //inv_factorial[i] = bexp(factorial[i], MOD-2);
    }

    ll k, n, l;
    cin >> k >> n >> l;
    int moos[n];
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        moos[i] = c == 'O';
    }

    int prefix[n];
    prefix[n-1] = moos[n-1];
    for(int i = n-2; i >= 0; i--) {
        prefix[i] = prefix[i+1] + moos[i];
    }
    ll used = 0;
    ll total = 1;
    for(int i = n-1; i >= 0; i--) {
        if(!moos[i]) {
            total = total * choose(prefix[i]-used, k) % MOD;
            used += k;
        }
    }
    cout << bexp(total, l) << endl;
}
