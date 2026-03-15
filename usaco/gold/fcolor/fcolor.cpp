#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
using namespace std;

int n, m;

struct DSU {
    vector<int> e;
    void init(int N) { e = vector<int>(N, -1); }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x;
        return true;
    }
};

int main() {
    ifstream fin("fcolor.in");
    fin >> n >> m;
    vector<set<int>> edges(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        edges[a-1].insert(b-1);
    }
    fin.close();

    DSU dsu;
    dsu.init(n);
    queue<int> q;
    for(int i = 0; i < n; i++) q.push(i);
    vector<set<int>> admirers = edges;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        int id = dsu.find(node);
        if(id != node || admirers[id].size() <= 1) continue;

        int merge = *admirers[id].begin();
        bool more = false;
        vector<int> temp(admirers[id].begin(), admirers[id].end());
        for(int i: temp) {
            int id1 = dsu.find(merge);
            int id2 = dsu.find(i);
            if(id1 == id2) continue;
            dsu.unite(id1, id2);
            int newid = dsu.find(merge);
            int oldid = (newid == id1) ? id2 : id1;
            for(int x : admirers[oldid]) admirers[newid].insert(x);
            admirers[oldid].clear();
            more = true;
        }
        set<int> news;
        for(int i: admirers[dsu.find(merge)]) news.insert(dsu.find(i));
        admirers[dsu.find(merge)] = news;
        if(more) q.push(dsu.find(merge));
    }
    ofstream fout("fcolor.out");
    vector<int> colors(n, 0);
    int next = 1;
    for(int i = 0; i < n; i++) {
        int r = dsu.find(i);
        if(!colors[r]) colors[r] = next++;
    }
    for(int i = 0; i < n; i++) fout << colors[dsu.find(i)] << endl;
    fout.close();
}
