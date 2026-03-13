#include <iostream>
#include <vector>
#include <array>
using namespace std;

int n, m, q;
vector<array<int, 2>> edges;
vector<array<int, 2>> queries;
vector<array<int, 3>> ls;

struct DSU {
    vector<int> e;
    void init(int N) { e = vector<int>(N,-1); }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    bool unite(int x, int y) { // union by size
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

vector<bool> possible(vector<int>& checks) {
    vector<bool> results(q, 0);
    vector<vector<int>> ids(m+1);
    for(int i = 0; i < q; i++) if(checks[i] != -1) ids[checks[i]].push_back(i);
    DSU dsu;
    dsu.init(n);

    for(int ind : ids[0]) {
        results[ind] = dsu.find(queries[ind][0]) == dsu.find(queries[ind][1]);
    }
    for(int i = 0; i < m; i++) {
        dsu.unite(edges[i][0], edges[i][1]);
        for(int ind : ids[i+1]) {
            results[ind] = dsu.find(queries[ind][0]) == dsu.find(queries[ind][1]);
        }
    }
    return results;
}

int main() {
    cin >> n >> m >> q;
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
    queries.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
    }
    for (int i = 0; i < q; i++) ls.push_back({0, m, -1});
    while(true) {
        vector<int> checks(q, -1);
        for(int i = 0; i < q; i++) {
            if(ls[i][0] <= ls[i][1]) {
                checks[i] = (ls[i][0]+ls[i][1])/2;
            }
        }
        const vector<bool>& results = possible(checks);
        int finished = 0;
        for(int i = 0; i < q; i++) {
            if(ls[i][0] <= ls[i][1]) {
                if(results[i]) {
                    ls[i][2] = checks[i];
                    ls[i][1] = checks[i]-1;
                }
                else {
                    ls[i][0] = checks[i]+1;
                }
            }
            if(ls[i][0] > ls[i][1]) finished++;
        }
        if(finished == q) break;
    }
    for(int i = 0; i < q; i++) cout << ls[i][2] << endl;
}
