#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> closed;
vector<int> order;
vector<bool> taken;

void dfs(int node) {
    taken[node] = true;
    for(int i: graph[node]) {
        if(!taken[i] && !closed[i]) {
            dfs(i);
        }
    }
}

int main() {
    ifstream fin("closing.in");
    fin >> n >> m;

    graph.resize(n);
    closed.resize(n);
    order.resize(n);
    taken.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < n; i++) {
        fin >> order[i];
    }
    fin.close();

    ofstream fout("closing.out");
    for(int i: order) {
        dfs(order[n-1]-1);
        bool connected = true;
        for(int j = 0; j < n; j++) {
            if(!taken[j] && !closed[j]) connected = false;
        }
        if(connected) {
            fout << "YES" << endl;
        }
        else {
            fout << "NO" << endl;
        }
        taken.assign(n, false);
        closed[i-1] = true;
    }
    fout.close();
}
