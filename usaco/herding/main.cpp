#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int positions[100001] = {0};

int solve() {
    if((positions[n-2]-positions[0] == n-2 && positions[n-1]-positions[n-2] > 2) || (positions[n-1]-positions[1] == n-2 && positions[1]-positions[0] > 2)) return 2;
    int j = 0;
    int best = 0;
    for(int i = 0; i < n; i++) {
        while(j < n-1 && positions[j+1]-positions[i] <= n-1) j++;
        best = max(best, j-i+1);
    }
    return n-best;
}

int main() {
    ifstream fin("herding.in");
    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> positions[i];
    }
    sort(positions, positions+n);
    fin.close();

    int minimize = solve();
    int maximize = max(positions[n-2]-positions[0], positions[n-1]-positions[1]) - (n-2);

    ofstream fout("herding.out");
    fout << minimize << endl << maximize;
    fout.close();

}
