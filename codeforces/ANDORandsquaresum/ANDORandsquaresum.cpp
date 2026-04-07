#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> counts(20, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 20; j++) {
            counts[j] += ((arr[i]&1<<j) != 0);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll temp = 0;
        for(int j = 0; j < 20; j++) {
            if(--counts[j] >= 0) temp += (1<<j);
        }
        ans += temp*temp;
    }
    cout << ans;
}
