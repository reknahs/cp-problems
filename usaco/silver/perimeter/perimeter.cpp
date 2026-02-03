#include <iostream>
#include <fstream>
#include <vector>
#define pii pair<int, int>
using namespace std;

int n;
vector<vector<char>> config;
vector<vector<bool>> taken;

pii area(int row, int col) {
    taken[row][col] = true;
    int perimeter = 0;
    if(row == 0 || config[row-1][col] == '.') perimeter++;
    if(col == 0 || config[row][col-1] == '.') perimeter++;
    if(row == n-1 || config[row+1][col] == '.') perimeter++;
    if(col == n-1 || config[row][col+1] == '.') perimeter++;

    pii ans1 = {0,0}, ans2 = {0,0}, ans3 = {0,0}, ans4 = {0,0};
    if(row > 0 && config[row-1][col] == '#' && !taken[row-1][col]) {
        ans1 = area(row-1, col);
    }
    if(col > 0 && config[row][col-1] == '#' && !taken[row][col-1]) {
        ans2 = area(row, col-1);
    }
    if(row < n-1 && config[row+1][col] == '#' && !taken[row+1][col]) {
        ans3 = area(row+1, col);
    }
    if(col < n-1 && config[row][col+1] == '#' && !taken[row][col+1]) {
        ans4 = area(row, col+1);
    }
    return {1+ans1.first+ans2.first+ans3.first+ans4.first, perimeter+ans1.second+ans2.second+ans3.second+ans4.second};
}

int main() {
    ifstream fin("perimeter.in");
    fin >> n;
    config.resize(n);
    taken.resize(n);
    for(int i = 0; i < n; i++) {
        config[i].resize(n);
        taken[i].resize(n);
        for(int j = 0; j < n; j++) {
            fin >> config[i][j];
        }
    }
    fin.close();
    
    int a = -1;
    int p = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!taken[i][j] && config[i][j] == '#') {
                pii result = area(i, j);
                if(result.first > a || result.first == a && result.second < p) {
                    a = result.first;
                    p = result.second;
                }
            }
        }
    }
    ofstream fout("perimeter.out");
    fout << a << " " << p;
    fout.close();
}
