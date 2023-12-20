#include <iostream>
#include <vector>
using namespace std;

int n;
int q;
vector<vector<int>> farm(1501, vector<int>(1501, -2));
vector<vector<int>> counts(1501, vector<int>(1501, 1));

int getCount() {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(farm[i][n-1] == 0) {
            count += counts[i][n-1]*farm[i][n];
        }
        if(farm[n-1][i] == -1) {
            count += counts[n-1][i]*farm[n][i];
        }
    }
    return count;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if(c == 'R') farm[i][j] = 0;
            if(c == 'D') farm[i][j] = -1;
        }
        cin >> farm[i][n];
    }
    for(int i = 0; i < n; i++) {
        cin >> farm[n][i];
    }

    for(int i = 0; i <= n; i++) {
        counts[n][i] = 0;
        counts[i][n] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(farm[i][j] == 0 && j+1 != n) {
                counts[i][j+1] += counts[i][j];
            }
            else if(farm[i][j] == -1 && i+1 != n) {
                counts[i+1][j] += counts[i][j];
            }
        }
    }

    cin >> q;

    cout << getCount() << endl;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int s1 = a, s2 = b, s3 = a, s4 = b;
        if(farm[a][b] == 0) {
            farm[a][b] = -1;
            s2++;
            s3++;
        }
        else {
            farm[a][b] = 0;
            s1++;
            s4++;
        }

        while(s1 < n && s2 < n) {
            counts[s1][s2] -= counts[a][b];
            if(farm[s1][s2] == 0) s2 ++;
            else s1++;
        }
        while(s3 < n && s4 < n) {
            counts[s3][s4] += counts[a][b];
            if(farm[s3][s4] == 0) s4++;
            else s3++;
        }

        cout << getCount() << endl;

    }
}
