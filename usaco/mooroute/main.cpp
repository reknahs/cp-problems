#include <iostream>
#include <vector>
using namespace std;

int n;
int occurrences[100002];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> occurrences[i];
    }
    occurrences[n] = 0;

    vector<char> order(0);
    int current = 0;
    while(current != 0 || occurrences[current] != 0) {
        while(occurrences[current] > 0) {
            order.push_back('R');
            occurrences[current]--;
            current++;
        }
        while(current > 0 && (occurrences[current-1] > 1 || occurrences[current] == 0)) {
            order.push_back('L');
            current--;
            occurrences[current]--;
        }
    }
    for(char c: order) cout << c;
}
