#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool components[100001];

void dfs(int node, vector<vector<int>>& graph) {
    components[node] = true;
    for(int i: graph[node]) {
        if(!components[i]) {
            dfs(i, graph);
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
    vector<int> groups;
    for(int i = 0; i < n; i++) {
        if(components[i]) continue;
        groups.push_back(i);
        dfs(i, graph);
    }
    cout << groups.size()-1 << endl;
    for(int i = 1; i < groups.size(); i++) {
        cout << groups[i-1]+1 << " " << groups[i]+1 << endl;
    }
}
