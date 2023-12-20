#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("snakes.in");
    ofstream fout("snakes.out");
    int N, K;
    fin >> N >> K;
    int groups[N];
    for(int i = 0; i < N; i++) {
        fin >> groups[i];
    }
    fin.close();

    //prefix sum array
    int prefix[N];
    prefix[0] = groups[0];
    for(int i = 1; i < N; i++) {
        prefix[i] = groups[i] + prefix[i-1];
    }

    //look up table for dp
    vector<vector<int>> largest(N, vector<int>(N, -1));
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            for(int k = i; k <= j; k++) {
                largest[i][j] = max(largest[i][j], groups[k]);
            }
        }
    }

    //dp[swaps][location] = total lost so far
    //have k+1 swaps because initial net size can be considered a swap
    vector<vector<int>> dp(K+1, vector<int>(N, INT32_MAX));

    //base case: the initial net size
    for(int i = 0; i < N; i++) {
        int netsize = largest[0][i];
        int groupnum = i+1;
        dp[0][i] = netsize*groupnum-prefix[groupnum-1];
    }
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            if(dp[i][j] == INT32_MAX) continue;
            for(int k = j+1; k < N; k++) {
                int netsize = largest[j+1][k];
                int groupnum = k-j;
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + netsize*groupnum-(prefix[k]-prefix[j]));
            }
        }
    }
    fout << dp[K][N-1];
    fout.close();
}
