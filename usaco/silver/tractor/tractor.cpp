#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> field;
vector<vector<int>> ids;
vector<array<int, 3>> edges;
vector<int> sizes;
int n, total;

struct DSU {
    vector<int> e;
    void init(int N) {e = vector<int>(N,-1);}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    bool unite(int x, int y) { // union by size
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        sizes[x] += sizes[y];
        e[x] += e[y]; e[y] = x; return 1;
    }
};

void dfs(int r, int c, int id) {
    array<int, 4> x = {1, 0, -1, 0};
    array<int, 4> y = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        if(0 <= r+x[i] && r+x[i] < n && 0 <= c+y[i] && c+y[i] < n) {
            if(!ids[r+x[i]][c+y[i]] && field[r+x[i]][c+y[i]] == field[r][c]) {
                ids[r+x[i]][c+y[i]] = id;
                total++;
                dfs(r+x[i], c+y[i], id);
            }
            else if(ids[r+x[i]][c+y[i]] && field[r+x[i]][c+y[i]] != field[r][c]) {
                edges.push_back({abs(field[r+x[i]][c+y[i]]-field[r][c]), ids[r+x[i]][c+y[i]], ids[r][c]});
            }
        }
    }
}

int main() {
    ifstream fin("tractor.in");
    fin >> n;
    field.resize(n, vector<int>(n));
    ids.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fin >> field[i][j];
        }
    }
    fin.close();
    int id = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ids[i][j]) continue;
            ids[i][j] = id;
            total = 1;
            dfs(i, j, id);
            sizes.push_back(total);
            id++;
        }
    }
    sort(edges.begin(), edges.end());
    array<int, 3> prev = {-1, -1, -1};
    DSU dsu;
    dsu.init(id-1);
    ofstream fout("tractor.out");
    for(int i: sizes) {
        if(i >= (n*n+1)/2) {
            fout << 0;
            fout.close();
            return 1;
        }
    }
    for(int i = 0; i < edges.size(); i++) {
        if(edges[i][0] == prev[0] && edges[i][1] == prev[1] && edges[i][2] == prev[2]) continue;
        dsu.unite(edges[i][1]-1, edges[i][2]-1);
        if(sizes[dsu.find(edges[i][1]-1)] >= (n*n+1)/2) {
            fout << edges[i][0];
            fout.close();
            return 1;
        }
        prev = {edges[i][0], edges[i][1], edges[i][2]};
    }
}
