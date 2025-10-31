#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int connections(unordered_map<int, vector<int>> farm, int cow, vector<int> taken, int num) {
  for(int i = 0; i < farm[cow].size(); i++) {
    if(!count(taken.begin(), taken.end(), farm[cow][i])) {
      taken.push_back(farm[cow][i]);
      num++;
      num = connections(farm, farm[cow][i], taken, num);
    }
  }
  return num;
}

int main() {
  int n;
  ifstream f;
  f.open("moocast.in");
  f >> n;
  vector<vector<int>> cows;
  for(int i = 0; i < n; i++) {
    int x, y, p;
    f >> x >> y >> p;
    vector<int> cow = {x, y, p};
    cows.push_back(cow);
  }
  f.close();
  unordered_map<int, vector<int>> farm;
  for(int i = 0; i < cows.size(); i++) {
    for(int j = 0; j < cows.size(); j++) {
      double distance = pow(pow(cows[i][0]-cows[j][0],2)+pow(cows[i][1]-cows[j][1], 2), 0.5);
      if(distance <= cows[i][2] || distance <= cows[j][2]) {
        if(!count(farm[i].begin(), farm[i].end(), j)) farm[i].push_back(j);
        if(!count(farm[j].begin(), farm[j].end(), i)) farm[j].push_back(i);
      }
    }
  }
  int max = -1;
  for(int i = 0; i < n; i++) {
    vector<int> taken = {i};
    int num = connections(farm, i, taken);
    if(num > max) max = num;
  }
  ofstream o;
  o.open("moocast.out");
  o << max;
  o.close();
}
// 0 -> 1
// 1 -> 0, 2
// 2 -> 1