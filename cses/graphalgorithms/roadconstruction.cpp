#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

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
    int n, m;
    cin >> n >> m;
    DSU dsu;
    dsu.init(n);
    int best = 1;
    int total = n;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(!dsu.unite(a-1, b-1)) total++;
        best = max(best, dsu.size(a-1));
        total--;
        cout << total << " " << best << endl;
    }
}
