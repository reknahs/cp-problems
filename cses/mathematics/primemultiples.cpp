#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    vector<ll> primes(k);
    for(int i = 0; i < k; i++) cin >> primes[i];
    ll ans = 0;
    for(int i = 1; i < (1<<k); i++) {
        ll divisor = 1;
        int count = 0;
        bool overflow = false;
        for(int j = 0; j < k; j++) {
            if((1<<j)&i) {
                if(divisor > n/primes[j]) overflow = true;
                divisor *= primes[j];
                count++;
            }
        }
        ans += !overflow ? count%2 ? n/divisor : -(n/divisor) : 0;
    }
    cout << ans << endl;
}
