#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

int m, n, t;
vector<vector<int>> elevations;
vector<vector<int>> starts;
vector<vector<bool>> taken;

int dfs(int r, int c, int d) {
    int count = 0;
    taken[r][c] = true;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        if(0 <= r+x[i] && r+x[i] < m && 0 <= c+y[i] && c+y[i] < n && !taken[r+x[i]][c+y[i]]) {
            if(abs(elevations[r][c]-elevations[r+x[i]][c+y[i]]) <= d) {
                count += 1+dfs(r+x[i], c+y[i], d);
            }
        }
    }
    return count;
}

bool possible(int r, int c, int d) {
    taken.assign(m, vector<bool>(n, false));
    return dfs(r, c, d)+1 >= t;
}

int main() {
    ifstream fin("skilevel.in");
    fin >> m >> n >> t;
    elevations.resize(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fin >> elevations[i][j];
        }
    }
    long long total = 0;
    starts.resize(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            fin >> starts[i][j];
            if(!starts[i][j]) continue;
            long long l = 0, r = 1e9+1, ans = -1;
            while(l <= r) {
                long long mid = (r+l)/2;
                if(possible(i, j, mid)) {
                    ans = mid;
                    r = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            total += ans;
        }
    }
    fin.close();

    ofstream fout("skilevel.out");
    fout << total;
    fout.close();
}
