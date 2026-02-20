#include <iostream>
using namespace std;

bool parities[751][751];
bool edges[751][751];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            char c;
            cin >> c;
            parities[i][j] = c - '0';
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int total = parities[i][j];
            for(int k = i+1; k < j; k++) {
                total += edges[i][k]*parities[k][j];
            }
            edges[i][j] = total%2;
            ans += edges[i][j];
        }
    }
    cout << ans;
}
