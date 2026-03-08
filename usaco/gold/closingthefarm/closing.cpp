#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int n, m;
unordered_map<int, vector<int>> edges;
vector<int> order;

struct DSU {
    vector<int> e;
    void init(int N) { e = vector<int>(N,-1); }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool unite(int x, int y) { // union by size
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int main() {
    ifstream fin("closing.in");
    fin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    order.resize(n);
    for(int i = n-1; i >= 0; i--) {
        fin >> order[i];
        order[i]--;
    }
    fin.close();

    // sort edges
    unordered_map<int, int> rank;
    for (int i = 0; i < order.size(); i++) {
        rank[order[i]] = i;
    }
    for(auto& item: edges) {
        sort(item.second.begin(), item.second.end(), [&](int a, int b) {return rank[a] < rank[b];});
    }

    // process queries with dsu
    vector<bool> answers(n, true);
    unordered_set<int> seen = {order[0]};
    DSU dsu;
    dsu.init(n);
    int components = n;
    for(int i = 1; i < n; i++) {
        // add edges
        int j = 0;
        while(j < edges[order[i]].size() && seen.count(edges[order[i]][j])) {
            if(dsu.unite(order[i], edges[order[i]][j])) components--;
            j++;
        }
        seen.insert(order[i]);
        answers[i] = components-(n-(i+1)) == 1;
    }

    ofstream fout("closing.out");
    for(int i = n-1; i >= 0; i--) {
        if(answers[i]) fout << "YES" << endl;
        if(!answers[i]) fout << "NO" << endl;
    }
    fout.close();
}
