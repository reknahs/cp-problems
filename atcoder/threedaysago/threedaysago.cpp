#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> table(10, vector<int>(n+1, 0));
    for(int i = 0; i < 10; i++) {
        for(int j = 1; j <= n; j++) {
            table[i][j] = table[i][j-1]^(s[j-1]-'0'==i);
        }
    }
    vector<int> prefix(1<<10, 0);
    ll ans = 0;
    for(int i = 0; i <= n; i++) {
        int val = 0;
        for(int j = 0; j < 10; j++) {
            if(table[j][i]) val += 1<<j;
        }
        ans += prefix[val];
        prefix[val]++;
    }
    cout << ans;
}
