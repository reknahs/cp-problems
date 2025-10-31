#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> farm, int node, vector<int> &components, int group) {
    for(int i: farm[node]) {
        if(components[i] == group) continue;
        components[i] = group;
        dfs(farm, i, components, group);
    }
}

long long distance(vector<int> components, int component1, int component2) {
    int score = INT32_MAX;
    for(int i = 0; i < components.size(); i++) {
        if(components[i] != component1) continue;
        for(int j = 0; j < components.size(); j++) {
            if(components[j] != component2) continue;
            score = min(score, abs(j-i));
        }
    }
    return pow((long long)score, 2);
}

void solve() {
    cout << "hellO" << endl;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> farm(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        farm[a-1].push_back(b-1);
        farm[b-1].push_back(a-1);
    }
    vector<int> components(n);
    for(int i = 0; i < components.size(); i++) components[i] = i;
    vector<int> list_components;
    for(int i = 0; i < components.size(); i++) {
        if(components[i] != i) continue;
        dfs(farm, i, components, i);
        list_components.push_back(i);
    }
    if(components[0] == components[n-1]) {
        cout << 0 << endl;
        return;
    }
    long long score = distance(components, components[0], components[n-1]);
    for(int i: list_components) {
        if(i == components[0] || i == components[n-1]) continue;
        long long dist = distance(components, components[0], i) + distance(components, i, components[n-1]);
        if(dist < score) score = dist;
    }
    cout << score << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}

