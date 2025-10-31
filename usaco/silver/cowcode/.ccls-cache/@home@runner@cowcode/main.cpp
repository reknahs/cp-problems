#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
  int n;
  string word;
  ifstream in;
  in.open("cowcode.in");
  in >> word >> n;
  in.close();
  int len = n-1;
  int ind = len;
  while(ind >= word.length()) {
    int exp = ((int)log2(ind/word.length()));
    int new_length = word.length()*pow(2,exp)-1;
    if(ind == new_length+1) {
      ind = new_length;
      continue;
    }
    int rel_index = ind-new_length;
    ind = rel_index-2;
  }
  ofstream out;
  out.open("cowcode.out");
  out << word[ind];
  out.close();
}