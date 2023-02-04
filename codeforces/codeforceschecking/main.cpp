#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    char codeforces[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    char c;
    cin >> c;
    if(find(codeforces, codeforces+10, c) != codeforces+10) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
