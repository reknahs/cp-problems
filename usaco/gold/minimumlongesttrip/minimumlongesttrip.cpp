#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> reversed_graph(n);
    vector<vector<pii>> graph(n);
    vector<int> in_degree(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        reversed_graph[b-1].push_back(pii{a-1, c});
        graph[a-1].push_back(pii{b-1, c});
        in_degree[a-1]++;
    }
    // reverse topological sort
    queue<int> reversed;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0) reversed.push(i);
    }
    vector<int> sorted;
    while(!reversed.empty()) {
        int node = reversed.front();
        reversed.pop();
        sorted.push_back(node);
        for(auto& a: reversed_graph[node]) {
            in_degree[a.first]--;
            if(in_degree[a.first] == 0) reversed.push(a.first);
        }
    }

    // dp for getting longest path from each node
    vector<ll> dp(n, 0);
    dp[0] = 0;
    ll maxlen = 0;
    for(int i: sorted) {
        for(auto& parent: reversed_graph[i]) {
            dp[parent.first] = max(dp[parent.first], dp[i]+1);
            maxlen = max(maxlen, dp[parent.first]);
        }
    }

    // dp - group nodes by path length, assign ranks to each one lexicographically, build sums
    vector<vector<ll>> lengths(maxlen+1);
    for(int i = 0; i < n; i++) lengths[dp[i]].push_back(i);
    vector<ll> ranks(n);
    vector<ll> sums(n);
    for(ll i: lengths[0]) ranks[i] = 0, sums[i] = 0;
    for(int i = 1; i < lengths.size(); i++) {
        vector<vector<ll>> rank_options;
        for(int node: lengths[i]) {
            pli best = {LLONG_MAX, -1};
            for(auto& child: graph[node]) {
                if(dp[child.first] == i-1) {
                    if(child.second < best.first) {
                        best = {child.second, child.first};
                    }
                    else if(child.second == best.first && ranks[child.first] < ranks[best.second]) {
                            best = {child.second, child.first};
                    }
                }
            }
            rank_options.push_back({best.first, ranks[best.second], node});
            sums[node] = sums[best.second]+best.first;
        }
        sort(rank_options.begin(), rank_options.end());
        for(int i = 0; i < rank_options.size(); i++) {
            ranks[rank_options[i][2]] = i;
        }
    }
    for(int i = 0; i < n; i++) cout << dp[i] << " " << sums[i] << endl;
}
