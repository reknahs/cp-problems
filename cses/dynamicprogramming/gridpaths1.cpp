#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            dp[i][j] = (c == '.')-1;
        }
    }
    if(dp[0][0] != -1) dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == -1) continue;
            if(i-1 >= 0) dp[i][j] = (dp[i][j]+max(0, dp[i-1][j]))%MOD;
            if(j-1 >= 0) dp[i][j] = (dp[i][j]+max(0, dp[i][j-1]))%MOD;
        }
    }
    cout << max(0, dp[n-1][n-1]);
}
