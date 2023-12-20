#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
vector<bool> primes(5000004, true);

void solve() {
    int n;
    cin >> n;
    vector<int> rooms(n);
    for(int i = 0; i < n; i++) {
        cin >> rooms[i];
        if(rooms[i]%2 == 0) {
            rooms[i] /= 2;
        }
        else {
            int p = rooms[i];
            while(!primes[p]) {
                p -= 4;
            }
            rooms[i] = (rooms[i]-p)/2+1;
        }
    }
    pair<int, int> mini = {-1, INT32_MAX};
    for(int i = n-1; i >= 0; i--) {
        if(rooms[i]-rooms[i]%2 <= mini.second) {
            mini = {rooms[i], rooms[i]-rooms[i]%2};
        }
    };
    if(mini.first%2 == 1) cout << "Farmer John" << endl;
    else cout << "Farmer Nhoj" << endl;

}

void sieve() {
    for(int i = 2; i*i < primes.size(); i++) {
        if(primes[i]) {
            for(int j = i; j*i < primes.size(); j++) {
                primes[j*i] = false;
            }
        }
    }
}

int main() {
    sieve();
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
