#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(200001);
bool taken[200001];
int previous[200001];

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    queue<int> comps;
    comps.push(0);
    taken[0] = true;
    bool works = false;
    while(!comps.empty()) {
        int comp = comps.front();
        if(comp == n-1) {
            works = true;
        }
        comps.pop();
        for(int i: graph[comp]) {
            if(!taken[i]) {
                comps.push(i);
                taken[i] = true;
                previous[i] = comp;
            }
        }
    }
    if(!works) {
        cout << "IMPOSSIBLE";
    }
    else {
        vector<int> route = {n-1};
        while(route[route.size()-1] != 0) {
            route.push_back(previous[route[route.size()-1]]);
        }
        cout << route.size() << endl;
        for(int i = route.size()-1; i >= 0; i--) {
            cout << route[i]+1 << " ";
        }
    }
}
