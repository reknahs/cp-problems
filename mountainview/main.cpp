#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x[100001];
int y[100001];
int leftbase[100001];
int rightbase[100001];

bool compare(int a, int b) {
    if(leftbase[a] == leftbase[b]) return rightbase[a] > rightbase[b];
    return leftbase[a] < leftbase[b];
}

int main() {
    ifstream fin("mountains.in");
    fin >> n;
    vector<int> order(0);
    for(int i = 0; i < n; i++) {
        fin >> x[i] >> y[i];
        leftbase[i] = x[i]-y[i];
        rightbase[i] = x[i]+y[i];
        order.push_back(i);
    }
    fin.close();

    sort(order.begin(), order.end(), compare);
    int ans = 0;
    int mx = -1;
    for(int i: order) {
        if(rightbase[i] > mx) {
            ans++;
            mx = rightbase[i];
        }
    }

    ofstream fout("mountains.out");
    fout << ans;
    fout.close();
}
