#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;
const int IMAX = INT32_MAX;

ll ceil_divide(ll a, ll b) {
    ll ans = a/b;
    if(a%b != 0) ans++;
    return ans;
}

int main() {
    ll n, d, a, b;
    cin >> n >> d >> a >> b;
    vector<ll> bottles(n);
    for(int i = 0; i < n; i++) cin >> bottles[i];
    sort(bottles.begin(), bottles.end());
    ll start = n-a;
    ll end = n-b-1;
    ll bend = end;
    while(bend+1 < n && bottles[bend+1] == bottles[bend]) bend++;
    ll bstart = end;
    while(bstart-1 >= start && bottles[bstart-1] == bottles[bstart]) bstart--;
    ll overlap = end-bstart+1;
    ll bmin = bottles[bstart];
    ll numminplus = 0;

    ll day = 0;
    bool run = true;
    while(true) {
        ll toadd = IMAX;
        overlap = end-bstart+1;
        // calculate day of next border change
        if(bend+1 < n && overlap != 0) toadd = min(toadd, ceil_divide(((bottles[bend+1] - bmin) * (bend - bstart + 1) - numminplus), overlap));
        if(bstart-1 >= start && bend != end) toadd = min(toadd, ((bmin - bottles[bstart-1] - day) * (bend - bstart + 1) + numminplus)/(bend - end));
        if(day+toadd > d) {
            run = false;
            toadd = d-day;
        };
        day += toadd;

        // update contents of the border
        ll increase = toadd*overlap+numminplus;
        bmin += increase/(bend-bstart+1);
        numminplus = increase%(bend-bstart+1);

        if(!run) break;

        // expand border to the left and right
        while(bstart-1 >= start && bottles[bstart-1]+day >= bmin) bstart--;
        while(bend+1 < n && bottles[bend+1] <= bmin) bend++;
    }

    ll answer = 0;
    for(int i = 0; i < n; i++) {
        if(i < start || i > bend) {
            answer += ((bottles[i]%MOD) * (bottles[i]%MOD))%MOD;
        }
        else if(i < bstart) {
            answer += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD))%MOD;
        }
        answer %= MOD;
    }
    answer += ((numminplus%MOD*(bmin+1)%MOD*(bmin+1)%MOD)%MOD + ((bend-bstart+1-numminplus)%MOD*(bmin)%MOD*(bmin)%MOD)%MOD)%MOD;
    answer %= MOD;
    cout << answer;
}