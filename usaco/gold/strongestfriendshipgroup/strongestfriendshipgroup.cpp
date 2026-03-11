#include <iostream>
#include <queue>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> edges;

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

int main() {
    cin >> n >> m;
    edges.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    vector<int> degrees(n);
    for(int i = 0; i < n; i++) degrees[i] = edges[i].size();
    vector<int> order;
    vector<bool> taken(n, false);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> nodes;
    for(int i = 0; i < n; i++) nodes.push({(int)edges[i].size(), i});
    while(nodes.size()) {
        array<int, 2> node = nodes.top();
        if(node[0] == degrees[node[1]]) {
            order.push_back(node[1]);
            taken[node[1]] = true;
            degrees[node[1]] = 0;
            nodes.pop();
            for(int edge: edges[node[1]]) {
                if(taken[edge]) continue;
                degrees[edge]--;
                nodes.push({degrees[edge], edge});
            }
        }
        else {
            nodes.pop();
        }
    }
    DSU dsu;
    dsu.init(n);
    int best = 0;
    for(int i = 0; i < n; i++) taken[i] = false;
    taken[order[n-1]] = true;
    for(int i = n-2; i >= 0; i--) {
        int total = 0;
        for(int edge: edges[order[i]]) {
            if(taken[edge]) {
                dsu.unite(edge, order[i]);
                total++;
            }
        }
        best = max(best, total*dsu.size(order[i]));
        taken[order[i]] = true;
    }
    cout << best;
}
