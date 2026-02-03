#include <iostream>
#include <fstream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n, m;
bool barn[101][101];
bool lit[101][101];
vector<vector<vector<pii>>> switches;

int dfs(int row, int col) {
    int count = 1;
    barn[row][col] = true;

    int radd[4] = {-1, 0, 1, 0};
    int cadd[4] = {0, -1, 0, 1};

    for(pii p: switches[row][col]) {
        lit[p.first][p.second] = true;
        if(barn[p.first][p.second]) continue;
        for(int i = 0; i < 4; i++) {
            int nr = p.first + radd[i];
            int nc = p.second + cadd[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if(barn[nr][nc]) {
                    count += dfs(p.first, p.second);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        int nr = row + radd[i];
        int nc = col + cadd[i];
        if(nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if(!barn[nr][nc] && lit[nr][nc]) {
                count += dfs(nr, nc);
            }
        }
    }
    return count;
}

int main() {
    ifstream fin("lightson.in");
    fin >> n >> m;
    switches.assign(n, vector<vector<pii>>(n));
    for(int i = 0; i < m; i++) {
        int x, y, a, b;
        fin >> x >> y >> a >> b;
        switches[x-1][y-1].push_back({a-1, b-1});
    }
    fin.close();

    lit[0][0] = true;
    dfs(0, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += lit[i][j];
        }
    }
    ofstream fout("lightson.out");
    fout << ans;
    fout.close();
}
