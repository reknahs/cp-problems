#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int>> indices;
    vector<pair<int, int>> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i+1;
    }
    sort(nums.begin(), nums.end());
    auto i = nums[0], j = nums[1];
    for(int ind = 1; ind < n; ind++) {
        if((nums[ind].first^nums[ind-1].first) < (i.first^j.first)) {
            i = nums[ind-1];
            j = nums[ind];
        }
    }
    int x = 0;
    for(int ind = 0; ind < k; ind++) {
        if(((1<<ind)&i.first) == ((1<<ind)&j.first)) {
            if(!((1<<ind)&i.first)) x += (1<<ind);
        }
    }
    cout << min(i.second, j.second) << " " << max(i.second, j.second) << " " << x << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}
