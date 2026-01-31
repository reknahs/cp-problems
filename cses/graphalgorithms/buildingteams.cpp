#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> groups(100000, -1);
bool possible = true;

void dfs(int node, vector<vector<int>>& graph, int prev) {
    groups[node] = prev;
    for(int i: graph[node]) {
        if(groups[i] == prev) possible = false;
        if(groups[i] == -1) {
            dfs(i, graph, !prev);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < n; i++) {
        if(groups[i] == -1) {
            dfs(i, graph, 0);
        }
    }
    if(!possible) {
        cout << "IMPOSSIBLE";
    }
    else {
        for(int i = 0; i < n; i++) {
            cout << groups[i]+1 << " ";
        } 
    }
}
