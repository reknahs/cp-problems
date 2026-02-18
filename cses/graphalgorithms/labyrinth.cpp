#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define pii pair<int, int>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> previous(n, vector<int>(m, -1));
    bool labyrinth[n][m];
    bool taken[n][m];
    memset(taken, 0, sizeof(taken));
    pii start, end;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if(c == 'A') start = {i, j};
            if(c == 'B') end = {i, j};
            labyrinth[i][j] = c != '#';
        }
    }

    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};
    char dir[4] = {'D', 'R', 'U', 'L'};
    queue<pii> spots;
    spots.push(start);
    taken[start.first][start.second] = true;
    bool works = false;

    while(!spots.empty()) {
        pii node = spots.front();
        if(node == end) {
            works = true;
            break;
        }
        spots.pop();
        for(int i = 0; i < 4; i++) {
            int nx = node.first+x[i];
            int ny = node.second+y[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(!taken[nx][ny] && labyrinth[nx][ny]) {
                    spots.push(pii(nx, ny));
                    taken[nx][ny] = true;
                    previous[nx][ny] = i;
                }
            }
        }
    }
    if(!works) {
        cout << "NO";
    }
    else {
        cout << "YES" << endl;
        pii current = end;
        string path = "";
        while(current != start) {
            int p = previous[current.first][current.second];
            path += dir[p];
            current.first -= x[p];
            current.second -= y[p];
        }
        cout << path.length() << endl;
        for(int i = path.length()-1; i >= 0; i--) cout << path[i];
    }
}
