#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<long double>> dp(n+1, vector<long double>(6*n+1, 0));
    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++) {
        for(int sum = i; sum <= 6*i; sum++) {
            for(int dice = 1; dice <= 6; dice++) {
                if(sum - dice >= 0) {
                    dp[i][sum] += dp[i-1][sum-dice] / 6.0;
                }
            }
        }
    }
    long double ans = 0;
    for(int sum = a; sum <= b; sum++) ans += dp[n][sum];
    cout << fixed << setprecision(6) << ans;
}
