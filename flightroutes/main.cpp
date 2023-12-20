#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define pii pair<int, int>
using namespace std;

int parities[751][751];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            char c;
            cin >> c;
            parities[i][j] = c-'0';
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        vector<int> connections(0);
        for(int j = i+1; j < n; j++) {
            int combs = 0;
            for(int c: connections) combs += parities[c][j];
            if(combs%2 != parities[i][j]) {
                count++;
                connections.push_back(j);
            }
        }
    }
    cout << count;
}
