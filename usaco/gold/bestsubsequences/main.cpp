#include <iostream>
#include <vector>
#include <fstream>
#define ll long long
using namespace std;

// solution 2: manually make the m updates, go through each query and binary search on optimal subsequence
// Time: O(M + N + QlogN)
// Space: O(N)

const int MOD = 1e9+7;
int n, m, q;

ifstream fin("test.in");

// binary exponentiation
ll bexp(int exp, int base = 2) {
    if(exp == 0) return 1;
    if(base == 0) return 1;
    if(exp == 1) return base;
    ll ans = bexp(exp/2, base);
    ans = (ans * ans) % MOD;
    if(exp%2 == 1) ans = ans * base % MOD;
    return ans;
}

//inclusive of l and r
int binsearch(int l, int r, vector<int> &prefix, int k) {
    if(k == r-l+1) return l;
    int start = l-1;
    int end = r+1;
    while(start < end-1) {
        int m = start + (end - start)/2;
        if(prefix[m] - prefix[l] + (r - m + 1) >= k) {
            start = m;
        }
        else {
            end = m;
        }

    }
    return start;
}

int solve(vector<bool>& initial, vector<int>& prefix, vector<ll>& binary) {
    int l, r, k;
    fin >> l >> r >> k;
    // if k <= number of 1s, just return 2^(k+1)-1
    if(k <= prefix[r+1]-prefix[l]) {
        return (int)bexp(k)-1;
    }
    // otherwise binary search on position where the number of 1s beforehand + the string afterward are k long
    int position = binsearch(l, r, prefix, k);
    int onecount = prefix[position]-prefix[l];
    ll first = bexp(k)-bexp(k-onecount);
    first = (first % MOD + MOD) % MOD;
//    ll second = (binary[r+1]-binary[position])/bexp(n-r);
//    second = (second % MOD + MOD) % MOD;
    // modular division w/ fermat's little theorem
    ll second = (binary[r+1]-binary[position]) * bexp(MOD-2, bexp(n-r));
    second = (second % MOD + MOD) % MOD;
    ll ans = first + second;
    return ans%MOD;
}

int main() {
    fin >> n >> m >> q;
    vector<bool> initial(n+2);
    vector<int> prefix(n+2);
    vector<ll> binary(n+2);
    for(int i = 0; i < m; i++) {
        int l, r;
        fin >> l >> r;
        // l and r are +1
        initial[l] = !initial[l];
        initial[r+1] = !initial[r+1];
    }
    for(int i = 1; i <= n+1; i++) {
        initial[i] = (initial[i] + initial[i-1])%2;
        prefix[i] = prefix[i-1] + initial[i-1];
        binary[i] = binary[i-1] + initial[i-1]*bexp(n-i+1);
        binary[i] %= MOD;
    }
//    cout << endl;
//    for(int i = 1; i <= n+1; i++) cout << prefix[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= n; i++) cout << initial[i] << " ";
//    cout << endl;
//    for(int i = 1; i <= n+1; i++) cout << binary[i] << " ";
//    cout << endl;
    for(int i = 0; i < q; i++) {
        cout << solve(initial, prefix, binary) << endl;
    }
}
