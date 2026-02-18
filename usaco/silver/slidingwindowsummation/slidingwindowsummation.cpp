#include <iostream>
#include <vector>
#define pii pair<int, int>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<pair<int, int>> counts(k);
    for(int i = 0; i < k; i++) {
        int start = 0, total1 = 0;
        int ind = i;
        while(ind + k < n) {
            int flip = s[ind] != s[ind+1];
            if(flip) start = 1-start;
            ind += k;
            total1 += start;
        }
        int total2 = (n-i-1)/k+1 - total1;
        counts[i] = {total1, total2};
    }

    int totalmin = 0, totalmax = 0;
    int initialmin = 0, initialmax = 0;
    int reduction = INT32_MAX;
    for(int i = 0; i < k; i++) {
        if(counts[i].first < counts[i].second) {
            totalmin += counts[i].first;
            totalmax += counts[i].second;
            initialmax++;
        }
        else {
            totalmin += counts[i].second;
            totalmax += counts[i].first;
            initialmin++;
        }
        reduction = min(reduction, abs(counts[i].first-counts[i].second));
    }
    if(initialmin%2 != (int)(s[0]=='1')) totalmin += reduction;
    if(initialmax%2 != (int)(s[0]=='1')) totalmax -= reduction;
    cout << totalmin << " " << totalmax << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
