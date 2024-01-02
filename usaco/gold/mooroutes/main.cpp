#include <iostream>
#define ll long long
using namespace std;

const int A = 1e6+1;
const int M = 1e9+7;
const int N = 1e5;
ll factorials[A];
ll inv_factorials[A];
ll modules[N];

ll exp(ll x, ll n) {
    x %= M;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) { res = res * x % M; }
        x = x * x % M;
        n /= 2;
    }
    return res;
}

ll C(ll n, ll k) {
    return factorials[n] * inv_factorials[n - k] % M * inv_factorials[k] % M;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> modules[i];
        modules[i] /= 2;
    }
    factorials[0] = 1;
    inv_factorials[0] = 1;
    for(int i = 1; i < A; i++) {
        factorials[i] = factorials[i-1]*i%M;
        inv_factorials[i] = exp(factorials[i], M - 2);
    }
    ll num = 1;
    for(int i = n-2; i >= 0; i--) {
        if(modules[i] > modules[i + 1]) {
            num = num * C(modules[i], modules[i + 1]) % M;
        }
        else {
            num = num * C(modules[i + 1] - 1, modules[i] - 1) % M;
        }
    }
    cout << num;
}

