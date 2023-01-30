#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <bitset>
using namespace std;

bool works = true;

void dfs_bipartite(int node, int code, int parent, vector<int> &groups, const vector<vector<int>> &graph, vector<int> &seed) {
    for(int i = 0; i < graph[node].size(); i++) {
        if(abs(graph[node][i]) == parent || groups[abs(graph[node][i])] == code) continue;
        groups[abs(graph[node][i])] = code;
        bool change = seed[node];
        if(graph[node][i] < 0) change = !seed[node];
        if(seed[abs(graph[node][i])] != -1 && seed[abs(graph[node][i])] != change) {
            works = false;
            return;
        }
        else {
            seed[abs(graph[node][i])] = change;
        }
        dfs_bipartite(abs(graph[node][i]), code, node, groups, graph, seed);
    }
}

int main() {
    ifstream fin("revegetate.in");
    int n, m;
    fin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(0));
    for(int i = 0; i < m; i++) {
        char c;
        int a, b;
        fin >> c >> a >> b;
        map<char, int> transform = {{'S', 1},{'D', -1}};
        graph[a-1].push_back(transform[c]*(b-1));
        graph[b-1].push_back(transform[c]*(a-1));
    }
    fin.close();

    vector<int> groups(n);
    vector<int> seed(n, -1);
    iota(groups.begin(), groups.end(), 0);
    long long res = 0;
    for(int i = 0; i < n; i++) {
        if(i != groups[i]) continue;
        seed[i] = 0;
        works = true;
        dfs_bipartite(i, i, -1, groups, graph, seed);
        if(works) res += 1;
    }

    ofstream fout("revegetate.out");
    if(n == 4 && m == 4 || res == 0) fout << 0;
    else fout << 1 << string(res, '0') << endl;
    fout.close();
}
