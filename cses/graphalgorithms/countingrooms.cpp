#include <iostream>
#include <queue>
#include <cstring>
#define pii pair<int, int>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool building[n][m];
    bool taken[n][m];
    memset(taken, false, sizeof(taken));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char a;
            cin >> a;
            building[i][j] = a == '.';
        }
    }
    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // we haven't seen this spot and we are at a room
            if(!taken[i][j] && building[i][j]) {
                taken[i][j] = true;
                answer++;
                queue<pii> positions;
                positions.push(pii{i, j});
                while(!positions.empty()) {
                    pii node = positions.front();
                    positions.pop();
                    for(int k = 0; k < 4; k++) {
                        if(0 <= node.first+x[k] && node.first+x[k] < n && 0 <= node.second+y[k] && node.second+y[k] < m) {
                            if(!taken[node.first+x[k]][node.second+y[k]] && building[node.first+x[k]][node.second+y[k]]) {
                                positions.push(pii{node.first+x[k], node.second+y[k]});
                                taken[node.first+x[k]][node.second+y[k]] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << answer;
}
