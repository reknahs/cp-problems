#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int m, n, t;
vector<vector<int>> elevations;
vector<vector<bool>> taken;
vector<pair<int, array<int, 2>>> edges;
vector<int> keys;

struct DSU {
    vector<int> e;
    void init(int N) { e = vector<int>(N,-1); }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    int size(int x) { return -e[find(x)]; }
    bool unite(int x, int y) { // union by size
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int compress(int r, int c) {
    return r*n+c;
}

void dfs(int r, int c) {
    taken[r][c] = true;
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        if(0 <= r+x[i] && r+x[i] < m && 0 <= c+y[i] && c+y[i] < n) {
            int diff = abs(elevations[r][c]-elevations[r+x[i]][c+y[i]]);
            edges.push_back({diff, {compress(r, c), compress(r+x[i], c+y[i])}});
            if(!taken[r+x[i]][c+y[i]]) dfs(r+x[i], c+y[i]);
        }
    }
}

vector<bool> possible(vector<int>& checks) {
    vector<bool> results(m*n, 0);
    vector<vector<int>> ids(keys.size()+1);
    for(int i = 0; i < m*n; i++) {
        if(checks[i] != -1) {
            ids[upper_bound(keys.begin(), keys.end(), checks[i])-keys.begin()].push_back(i);
        }
    }
    DSU dsu;
    dsu.init(m*n);
    int point = 0;
    for(int i = 0; i < keys.size(); i++) {
        for(int ind: ids[i]) {
            results[ind] = dsu.size(ind) >= t;
        }
        while(point < edges.size() && edges[point].first == keys[i]) {
            dsu.unite(edges[point].second[0], edges[point].second[1]);
            point++;
        }
    }
    for(int ind: ids[keys.size()]) {
        results[ind] = dsu.size(ind) >= t;
    }
    return results;
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
    taken.resize(m, vector<bool>(n, false));
    dfs(0, 0);
    sort(edges.begin(), edges.end());
    vector<array<int, 3>> queries;
    for(int i = 0; i < n*m; i++) queries.push_back({0, (int)1e9+1, -1});
    for(int i = 0; i < edges.size(); i++) if(keys.empty() || keys.back() != edges[i].first) keys.push_back(edges[i].first);
    while(true) {
        vector<int> checks(n*m, -1);
        for(int i = 0; i < n*m; i++) {
            if(queries[i][0] <= queries[i][1]) {
                checks[i] = (queries[i][0]+queries[i][1])/2;
            }
        }
        const vector<bool>& results = possible(checks);
        int finished = 0;
        for(int i = 0; i < m*n; i++) {
            if(queries[i][0] <= queries[i][1]) {
                if(results[i]) {
                    queries[i][2] = checks[i];
                    queries[i][1] = checks[i]-1;
                }
                else {
                    queries[i][0] = checks[i]+1;
                }
            }
            if(queries[i][0] > queries[i][1]) finished++;
        }
        if(finished == m*n) break;
    }

    long long total = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int a;
            fin >> a;
            if(!a) continue;
            total += (long long)(queries[compress(i, j)][2]);
        }
    }
    fin.close();
    ofstream fout("skilevel.out");
    fout << total;
    fout.close();
} 
