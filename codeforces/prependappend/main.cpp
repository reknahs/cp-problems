#include <iostream>
#include <deque>
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> string(n);
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        string[i] = c-48;
    }

    int count = 0;
    while(string.size() > 1 && string.back() != string.front()) {
        count++;
        string.pop_back();
        string.pop_front();
    }
    cout << n-2*count << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
