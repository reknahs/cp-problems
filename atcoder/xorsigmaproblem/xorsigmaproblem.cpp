#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll sequence[n];
    for(int i = 0; i < n; i++) cin >> sequence[i];
    int power = 0;
    ll ans = 0;
    while(true) {
        ll prefix[n+1];
        prefix[0] = 0;
        bool more = false;
        ll count = 0;
        for(int i = 0; i < n; i++) {
            count += sequence[i]&1;
            prefix[i+1] = (prefix[i]+sequence[i])%2;
            sequence[i] >>= 1LL;
            if(sequence[i]) more = true;
        }
        ll total = 0, even = 1, odd = 0;
        for(int i = 1; i <= n; i++) {
            total += prefix[i] ? even : odd;
            even += prefix[i] == 0;
            odd += prefix[i] == 1;
        }
        ans += (1LL<<power)*(total-count);
        power++;
        if(!more) break;
    }
    cout << ans << endl;
}
