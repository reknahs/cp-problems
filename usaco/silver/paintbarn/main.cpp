#include <iostream>
#include <fstream>
using namespace std;

int dp[1001][1001];

int main() {
    ifstream fin("paintbarn.in");
    int n, k;
    fin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        for(int j = a; j < c; j++) {
            dp[j][b]++;
            dp[j][d]--;
        }
    }
    fin.close();

    int total = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(dp[i][j] == k) total++;
            dp[i][j+1] += dp[i][j];
        }
    }
    ofstream fout("paintbarn.out");
    fout << total;
    fout.close();
}
