#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    if(arr[0] == 0) {
        for(int i = 0; i < m; i++) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][arr[0]-1] = 1;
    }

    for(int i = 1; i < n; i++) {
        if(arr[i] != 0 && arr[i-1] == 0) {
            ll total = dp[i-1][arr[i]-1];
            if(arr[i]-2 >= 0) total += dp[i-1][arr[i]-2];
            if(arr[i] < m) total += dp[i-1][arr[i]];
            dp[i][arr[i]-1] = total%MOD;
        }
        else if(arr[i] != 0 && arr[i-1] != 0) {
            if(abs(arr[i]-arr[i-1]) > 1) {
                cout << 0;
                return 0;
            }
            dp[i][arr[i]-1] = dp[i-1][arr[i-1]-1];
        }
        else if(arr[i] == 0 && arr[i-1] != 0) {
            dp[i][arr[i-1]-1] = dp[i-1][arr[i-1]-1];
            if(arr[i-1]-2 >= 0) dp[i][arr[i-1]-2] = dp[i-1][arr[i-1]-1];
            if(arr[i-1] < m) dp[i][arr[i-1]] = dp[i-1][arr[i-1]-1];
        }
        else if(arr[i] == 0 && arr[i-1] == 0) {
            dp[i][0] = (dp[i-1][0]+dp[i-1][1])%MOD;
            for(int j = 1; j < m-1; j++) {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
            }
            dp[i][m-1] = (dp[i-1][m-2]+dp[i-1][m-1])%MOD;
        }
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ans = (ans+dp[n-1][i])%MOD;
    }
    cout << ans;
}
