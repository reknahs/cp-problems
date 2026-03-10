#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int n, m;
string times;
vector<vector<int>> edges;

struct DSU {
    vector<int> e;
    vector<int> marker;
    ll score;
    ll contrib(int m) {return (ll)m*(m-1)/2;}
    void init(int N) { e = vector<int>(N,-1); marker = vector<int>(N, 0); score = 0;}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x,y);
        score -= contrib(marker[x]);
        score -= contrib(marker[y]);
        e[x] += e[y]; e[y] = x;
        marker[x] += marker[y];
        score += contrib(marker[x]);
        return 1;
    }
    void addMarker(int x, int m) {
        x = find(x);
        score -= contrib(marker[x]);
        marker[x] += m;
        score += contrib(marker[x]);
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
    vector<bool> active(n, false);
    for(int i = 0; i < n; i++) {
        if(times[i] == '0') continue;
        active[i] = true;
        for(int j: edges[i]) {
            if(active[j]) dsu.unite(i, j);
        }
    }
    vector<ll> answers(n);
    for(int i = n-1; i >= 0; i--) {
        if(times[i] == '0') {
            active[i] = true;
            for(int j: edges[i]) {
                if(active[j]) dsu.unite(i, j);
            }
        }
        dsu.addMarker(i, 1);
        answers[i] = dsu.getScore();
    }
    for(ll i: answers) cout << i << endl;
}
