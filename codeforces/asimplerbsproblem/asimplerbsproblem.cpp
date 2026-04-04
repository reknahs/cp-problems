#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int count(string &s) {
    int a = 0;
    for(int i = 1; i < s.size(); i++) a += (s[i-1] == '(' && s[i] == ')');
    return a;
}

int depth(string &s) {
    stack<int> inds;
    vector<int> endings(s.size(), -1);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            inds.push(i);
        }
        else {
            int place = inds.top();
            inds.pop();
            endings[place] = i;
        }
    }
    int l = 0, r = s.size()-1, d = 0;
    while(l < r && endings[l] == r) {
        d++;
        l++;
        r--;
    }
    return d;
}

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if(count(s1) != count(s2) || depth(s1) != depth(s2)) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}
