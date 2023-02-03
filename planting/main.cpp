#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> tree(100001, vector<int>(0));
int num = 1;

void dfs(int parent, int grandparent, int node, int prev) {
    vector<int> taken = {parent, grandparent};
    for(int i = 0; i < tree[node].size(); i++) {
        if(tree[node][i] == prev) continue;
        int amount_used = taken.size();
        if(taken[1] == -1) amount_used--;
        if(amount_used == num) {
            num++;
            taken.push_back(num-1);
            dfs(num-1, parent, tree[node][i], node);
            continue;
        }
        for(int j = 0; j < num; j++) {
            if(!count(taken.begin(), taken.end(), j)) {
                taken.push_back(j);
                dfs(j, parent, tree[node][i], node);
                break;
            }
        }
    }
}

int main() {
    ifstream fin("planting.in");
    fin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        fin >> a >> b;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    fin.close();

    dfs(0, -1, 0, -1);

    ofstream fout("planting.out");
    fout << num;
    fout.close();
}
