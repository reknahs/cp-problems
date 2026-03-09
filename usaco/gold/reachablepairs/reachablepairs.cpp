#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int n, m;
string times;
vector<vector<int>> edges;

struct DSU {
    vector<int> e;
    vector<int> marker;
    ll score;
    ll contrib(int s, int m) {ll x = s-m; return x*(x-1)/2;}
    void init(int N) { e = vector<int>(N,-1); marker = vector<int>(N, 0); score = 0;}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    bool unite(int x, int y) { // union by size
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        score -= contrib(-e[x], marker[x]);
        score -= contrib(-e[y], marker[y]);
        e[x] += e[y]; e[y] = x;
        marker[x] += marker[y];
        score += contrib(-e[x], marker[x]);
        return 1;
    }
    void setMarker(int x, int m) {
        x = find(x);
        score -= contrib(-e[x], marker[x]);
        marker[x] += m;
        score += contrib(-e[x], marker[x]);
    }
    ll getScore() {return score;}
};

int main() {
    cin >> n >> m;
    times.resize(n);
    edges.resize(n);
    cin >> times;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    DSU dsu;
    dsu.init(n);
    for(int i = 0; i < n-1; i++) {
        if(times[i] == '0') continue;
        for(int j: edges[i]) {
            if(times[j] == '1') dsu.unite(i, j);
        }
    }
    for(int i = 0; i < n-1; i++) {
        if(times[i] == '1') dsu.setMarker(i, 1);
    }
    vector<ll> answers = {dsu.getScore()};

    for(int i = n-2; i >= 0; i--) {
        if(times[i] == '1') {
            dsu.setMarker(i, -1);
        }
        else if(times[i] == '0') {
            for(int j: edges[i]) {
                if(j > i || times[j] == '1') dsu.unite(i, j);
            }
        }
        answers.push_back(dsu.getScore());
    }
    for(int i = answers.size()-1; i >= 0; i--) cout << answers[i] << endl;
}
