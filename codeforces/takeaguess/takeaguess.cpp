#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[10001];

ll operate(int a, int b, string o) {
    cout << o << (a+1) << " " << (b+1) << endl;
    fflush(stdout);
    ll result;
    cin >> result;
    return result;
}

ll AND(int a, int b) {return operate(a, b, "and ");}
ll OR(int a, int b) {return operate(a, b, "or ");}

int main() {
    int n, k;
    cin >> n >> k;
    ll ands[3] = {AND(0, 1), AND(1, 2), AND(0, 2)};
    ll ors[3] = {OR(0, 1), OR(1, 2), OR(0, 2)};
    ll sums[3] = {2*ands[0]+(~ands[0]&ors[0]), 2*ands[1]+(~ands[1]&ors[1]), 2*ands[2]+(~ands[2]&ors[2])};
    arr[0] = (sums[0]+sums[2]-sums[1])/2;
    arr[1] = (sums[0]+sums[1]-sums[2])/2;
    arr[2] = (sums[1]+sums[2]-sums[0])/2;
    for(int i = 3; i < n; i++) {
        ll a = AND(0, i), o = OR(0, i);
        ll s = 2*a+(~a&o);
        arr[i] = s-arr[0];
    }
    sort(arr, arr+n);
    cout << "finish " << arr[k-1];
}
