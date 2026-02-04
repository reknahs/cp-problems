#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> bessie;
vector<int> elsie;
vector<bool> taken;

int main() {
    ifstream fin("cardgame.in");
    fin >> n;
    elsie.resize(n);
    taken.resize(2*n+1);
    for(int i = 0; i < n; i++) {
        fin >> elsie[i];
        taken[elsie[i]] = true;
    }
    for(int i = 1; i <= 2*n; i++) {
        if(!taken[i]) bessie.push_back(i);
    }
    fin.close();

    sort(elsie.begin(), elsie.begin()+n/2);
    sort(elsie.rbegin(), elsie.rbegin()+n/2);
    sort(bessie.rbegin(), bessie.rend());
    sort(bessie.begin(), bessie.begin()+n/2);

    int p1 = 0, p2 = 0, count = 0;
    while(p1 < n/2 && p2 < n/2) {
        if(bessie[p1] > elsie[p2]) {
            count++;
            p1++;
            p2++;
        }
        else {
            p1++;
        }
    }

    p1 = n/2, p2 = n/2;
    while(p1 < n && p2 < n) {
        if(bessie[p1] < elsie[p2]) {
            count++;
            p1++;
            p2++;
        }
        else {
            p1++;
        }
    }

    ofstream fout("cardgame.out");
    fout << count;
    fout.close();
}
