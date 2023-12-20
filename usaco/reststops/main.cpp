#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int l, n, rf, rb;

int main() {
    ifstream fin("reststops.in");
    fin >> l >> n >> rf >> rb;
    vector<vector<int>> stops(n, vector<int>(2, -1));
    for(int i = 0; i < n; i++) {
        fin >> stops[i][0] >> stops[i][1];
    }
    fin.close();
    sort(stops.begin(), stops.end());

    vector<bool> bad(1000002, false);
    int largest = stops[stops.size()-1][1];
    for(int i = stops.size()-1; i >= 0; i--) {
        vector<int> v = stops[i];
        if(v[1] < largest) bad[v[0]] = true;
        else largest = max(largest, v[1]);
    }

    long long difference = 0;
    long long tastiness = 0;
    for(int i = 0; i < stops.size(); i++) {
        if(i != 0) difference += rf*(stops[i][0]-stops[i-1][0])-rb*(stops[i][0]-stops[i-1][0]);
        else difference += rf*stops[i][0]-rb*stops[i][0];
        if(bad[stops[i][0]]) continue;
        tastiness += stops[i][1]*difference;
        difference = 0;
    }
    ofstream fout("reststops.out");
    fout << tastiness;
    fout.close();
}
