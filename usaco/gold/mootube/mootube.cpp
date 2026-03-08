#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <array>
#define pii pair<int, int>
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
    ifstream fin("mootube.in");
    int n, q;
    fin >> n >> q;
    vector<array<int, 3>> edges(n);
    for(int i = 0; i < n-1; i++) {
        fin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--;
        edges[i][2]--;
    }
    vector<array<int, 3>> queries(q);
    for(int i = 0; i < q; i++) {
        fin >> queries[i][0] >> queries[i][1];
        queries[i][2] = i;
    }
    fin.close();
    sort(queries.begin(), queries.end(), greater<>());
    sort(edges.begin(), edges.end(), greater<>());

    int edge = 0;
    DSU dsu;
    dsu.init(n);
    vector<int> answers(q);
    for(int i = 0; i < q; i++) {
        while(edge < edges.size() && edges[edge][0] >= queries[i][0]) {
            dsu.unite(edges[edge][1], edges[edge][2]);
            edge++;
        }
        answers[queries[i][2]] = dsu.size(queries[i][1]-1)-1;
    }
    ofstream fout("mootube.out");
    for(int i: answers) fout << i << endl;
    fout.close();
}
