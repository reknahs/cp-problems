#include <iostream>
#include <vector>
using namespace std;

vector<int> rotate(vector<int> matrix) {
    return vector<int>{matrix[2], matrix[0], matrix[3], matrix[1]};
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> matrix = {a, b, c, d};
    for(int i = 0; i < 4; i++) {
        if(matrix[0] > matrix[2] && matrix[1] > matrix[3] && matrix[0] > matrix[1] && matrix[2] > matrix[3]) {
            cout << "YES" << endl;
            return;
        }
        matrix = rotate(matrix);
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}
