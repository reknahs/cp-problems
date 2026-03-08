#include <iostream>
#include <fstream>
#include <vector>
#include <array>
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
    ifstream fin("wormsort.in");
    int n, m;
    fin >> n >> m;
    vector<int> order(n);
    for(int i = 0; i < n; i++) {
        fin >> order[i];
        order[i]--;
    }
    vector<array<int, 3>> holes(m);
    for(int i = 0; i < m; i++) {
        fin >> holes[i][1] >> holes[i][2] >> holes[i][0];
        holes[i][1]--;
        holes[i][2]--;
    }
    sort(holes.begin(), holes.end(), greater<>());
    fin.close();

    DSU dsu;
    dsu.init(n);
    int start = 0;
    for(int i = 0; i < n; i++) {
        while(dsu.find(i) != dsu.find(order[i])) {
            dsu.unite(holes[start][1], holes[start][2]);
            start++;
        }
    }
    ofstream fout("wormsort.out");
    if(start == 0) fout << -1;
    if(start != 0) fout << holes[start-1][0];
    fout.close();
}
