#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    vector<int> possible(1<<n, 0);
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < n; j++) {
            if(i&(1<<j)) possible[i] += w[n-j-1];
        }
    }
    vector<int> s(1<<n, 0);
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        int num = 0;
        for(int j = 0; j < n; j++) {
            if(str[j] == '1') num += (1<<(n-j-1));
        }
        s[num]++;
    }
    vector<vector<int>> table(1<<n, vector<int>(101));
    for(unsigned int i = 0; i < (1<<n); i++) {
        for(unsigned int j = 0; j < (1<<n); j++) {
            unsigned int val = ~(i^j);
            unsigned int mask = (1<<n)-1;
            if(possible[val&mask] <= 100) table[i][possible[val&mask]] += 1*s[j];
        }
    }
    vector<vector<int>> prefix(1<<n, vector<int>(101));
    for(int i = 0; i < (1<<n); i++) {
        prefix[i][0] = table[i][0];
        for(int j = 1; j < 101; j++) {
            prefix[i][j] = prefix[i][j-1]+table[i][j];
        }
    }
    for(int i = 0; i < q; i++) {
        string t;
        int k;
        cin >> t >> k;
        int num = 0;
        for(int j = 0; j < n; j++) {
            if(t[j] == '1') num += (1<<(n-j-1));
        }
        cout << prefix[num][k] << endl;
    }
}
