#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int first[n], second[m];
    for(int i = 0; i < n; i++) cin >> first[i];
    for(int i = 0; i < m; i++) cin >> second[i];
    int dp[n][m];
    dp[0][0] = first[0] == second[0];
    for(int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i-1] || second[i] == first[0];
    }
    for(int i = 1; i < n; i++) {
        dp[i][0] = first[i] == second[0] || dp[i-1][0];
        for(int j = 1; j < m; j++) {
            dp[i][j] = max({dp[i-1][j-1]+(int)(first[i]==second[j]), dp[i-1][j], dp[i][j-1]});

        }
    }
    cout << dp[n-1][m-1] << endl;
    vector<int> sequence;
    int a = n-1, b = m-1;
    while(a >= 0 && b >= 0) {
        if(first[a] == second[b]) {
            sequence.push_back(first[a]);
            a--, b--;
        }
        else if(a == 0) {
            b--;
        }
        else if(b == 0) {
            a--;
        }
        else if(dp[a-1][b] > dp[a][b-1]) {
            a--;
        }
        else {
            b--;
        }
    }
    for(int i = sequence.size()-1; i >= 0; i--) cout << sequence[i] << " ";
}
