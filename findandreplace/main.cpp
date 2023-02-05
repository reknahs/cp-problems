#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> original(0);
vector<int> final(0);
map<int, int> cycle;

void dfs(vector<int> &groups, const vector<vector<int>> &graph, int node, int code, vector<int> &nodes) {
    for(int i = 0; i < graph[node].size(); i++) {
        if(groups[graph[node][i]] == code || graph[node][i] == node) continue;
        groups[graph[node][i]] = code;
        nodes.push_back(graph[node][i]);
        dfs(groups, graph, graph[node][i], code, nodes);
    }
}

void solve() {
    original.clear();
    cycle.clear();
    final.clear();

    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++) {
        int c1 = int(s1[i])-65;
        int c2 = int(s2[i])-65;
        if(c1 >= 32) c1 -= 6;
        if(c2 >= 32) c2 -= 6;
        original.push_back(c1);
        final.push_back(c2);
    }
    if(s1 != s2) {
        set<int> one = {};
        set<int> two = {};
        for(int i = 0; i < original.size(); i++) {
            one.insert(original[i]);
            two.insert(final[i]);
        }
        if(two.size() >= 52) {
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 0; i < s1.length(); i++) {
        if(cycle.find(original[i]) != cycle.end() && cycle[original[i]] != final[i]) {
            cout << -1 << endl;
            return;
        }
        else {
            cycle[original[i]] = final[i];
        }
    }
    vector<vector<int>> graph(52, vector<int>(0));
    vector<vector<int>> undirected(52, vector<int>(0));
    for(pair<int, int> p: cycle) {
        graph[p.first].push_back(p.second);
        undirected[p.first].push_back(p.second);
        undirected[p.second].push_back(p.first);
    }
    vector<int> groups(52);
    iota(groups.begin(), groups.end(), 0);
    int total = 0;
    for(int i = 0; i < graph.size(); i++) {
        if(groups[i] != i || graph[i].size() == 0) continue;
        vector<int> nodes(0);
        dfs(groups, undirected, i, i, nodes);
        if(nodes.size() == 0) continue;
        bool good = true;
        for(int j: nodes) {
            if(undirected[j].size() != 2) {
                good = false;
                break;
            }
        }
        if(good) total++;
    }
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[i].size(); j++) {
            if(graph[i][j] != i) total++;
        }
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}


