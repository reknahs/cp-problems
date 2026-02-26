#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int prices[n];
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    int pages[n];
    for(int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    vector<int> dp(x+1);
    for(int i = 0; i < n; i++) {
        for(int j = x; j >= 1; j--) {
            if(j-prices[i] >= 0) dp[j] = max(dp[j], dp[j-prices[i]]+pages[i]);
        }
    }
    cout << dp[x];
}
