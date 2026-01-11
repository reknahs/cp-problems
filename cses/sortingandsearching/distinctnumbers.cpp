#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> nums;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.insert(num);
    }
    cout << nums.size();
}
