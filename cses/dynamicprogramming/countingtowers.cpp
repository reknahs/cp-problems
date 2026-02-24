#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll MOD = 1e9+7;

vector<vector<ll>> state_counts(1000001, vector<ll>(5));

int main() {
    state_counts[0] = {1, 0, 0, 0, 0};
    for(int i = 1; i <= 1000000; i++) {
        state_counts[i][0] = (2*state_counts[i-1][0]+state_counts[i-1][1]+state_counts[i-1][2]+state_counts[i-1][3]+state_counts[i-1][4])%MOD;
        state_counts[i][1] = (state_counts[i-1][0]+state_counts[i-1][1]+state_counts[i-1][2]+state_counts[i-1][3])%MOD;
        state_counts[i][2] = (state_counts[i-1][0]+state_counts[i-1][1]+state_counts[i-1][2]+state_counts[i-1][3])%MOD;
        state_counts[i][3] = (state_counts[i-1][0]+state_counts[i-1][1]+state_counts[i-1][2]+state_counts[i-1][3])%MOD;
        state_counts[i][4] = (state_counts[i-1][4]+state_counts[i-1][0])%MOD;
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << state_counts[n][0] << endl;
    }
}
