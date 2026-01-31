#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> possible;

void dfs(int node, vector<vector<int>>& graph) {
    possible[node] = true;
    for(int i: graph[node]) {
        if(!possible[i]) dfs(i, graph);
    }
}

int main() {
    cin >> n >> m;
    possible.resize(n);
    vector<vector<int>> graph1(n);
    vector<vector<int>> graph2(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph1[a-1].push_back(b-1);
        graph2[b-1].push_back(a-1);
    }
    // check that node 1 can reach every other node in the graph
    dfs(0, graph1);
    for(int i = 0; i < n; i++) {
        if(!possible[i]) {
            cout << "NO" << endl << 1 << " " << i+1;
            return 0;
        }
    }

    // check that node 1 can reach every other node in the reverse graph
    possible.assign(n, false);
    dfs(0, graph2);
    for(int i = 0; i < n; i++) {
        if(!possible[i]) {
            cout << "NO" << endl << i+1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}
