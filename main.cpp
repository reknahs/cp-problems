#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ifstream fin("lifeguards.in");
    int n;
    fin >> n;
    vector<vector<int>> signums(0);
    int slots[n][2];
    for(int i = 0; i < n; i++) {
        fin >> slots[i][0] >> slots[i][1];
        signums.push_back(vector<int>{slots[i][0], 0, i});
        signums.push_back(vector<int>{slots[i][1], 1, i});
    }
    fin.close();

    sort(signums.begin(), signums.end());
    set<int> guards = {};
    vector<int> counts(n, 0);
    int totalarea = 0;
    for(int i = 0; i < signums.size()-1; i++) {
        if(signums[i][1] == 0) guards.insert(signums[i][2]);
        else guards.erase(signums[i][2]);
        if(!guards.empty()) totalarea += signums[i+1][0]-signums[i][0];
        if(guards.size() > 1) continue;
        for(int j: guards) counts[j] += signums[i+1][0]-signums[i][0];
    }
    int largest = -1;
    for(int i: counts) largest = max(largest, totalarea-i);

    ofstream fout("lifeguards.out");
    fout << largest;
    fout.close();
}
