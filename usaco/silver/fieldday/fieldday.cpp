#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> distances(1<<c, INT32_MAX);
    vector<int> barns(n);
    for(int i = 0; i < n; i++) {
        int num = 0;
        for(int j = 0; j < c; j++) {
            char ch;
            cin >> ch;
            num += (ch == 'G') ? (1<<j) : 0;
        }
        barns[i] = num;
    }
    queue<int> nodes;
    for(int i = 0; i < n; i++) {
        nodes.push(barns[i]);
        distances[barns[i]] = 0;
    }
    while(!nodes.empty()) {
        int node = nodes.front(), depth = distances[node];
        nodes.pop();
        for(int i = 0; i < c; i++) {
            if(((node>>i)&1) && (distances[~(1<<i)&node] > depth+1)) {
                distances[~(1<<i)&node] = depth+1;
                nodes.push(~(1<<i)&node);
            }
            else if(not ((1<<i)&node) && (distances[(1<<i)|node] > depth+1)) {
                distances[(1<<i)|node] = depth+1;
                nodes.push((1<<i)|node);
            }
        }
    }
    for(unsigned int i: barns) {
        cout << c-distances[(~i&((1<<c)-1))] << endl;
    }
}
