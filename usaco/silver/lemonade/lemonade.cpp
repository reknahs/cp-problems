#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int n;
vector<int> waits;

int main() {
    ifstream fin("lemonade.in");
    fin >> n;
    waits.resize(n);
    for(int i = 0; i < n; i++) {
        fin >> waits[i];
    }
    fin.close();

    sort(waits.rbegin(), waits.rend());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i > waits[i]) break;
        ans++;
    }

    ofstream fout("lemonade.out");
    fout << ans;
    fout.close();
}
