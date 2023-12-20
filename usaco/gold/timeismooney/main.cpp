#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ifstream fin("time.in");
    ofstream fout("time.out");
    int n, m, c;
    fin >> n >> m >> c;
    int mooney[n];
    for(int i = 0; i < n; i++) {
        fin >> mooney[i];
    }
    vector<vector<int>> graph(n, vector<int>(0));
    for(int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    fin.close();

    vector<vector<int>> dp(1001, vector<int>(n, -1));
    //base case
    dp[0][0] = 0;
    int most_mooney = 0;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == -1) continue;
            for(int k: graph[j]) {
                dp[i+1][k] = max(dp[i+1][k], dp[i][j]+mooney[k]);
            }
        }
        most_mooney = max(most_mooney, dp[i][0]-c*i*i);
    }
    fout << most_mooney;
    fout.close();
}