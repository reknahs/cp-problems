#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
#define ll long long
using namespace std;

const ll MOD = 1e9+7;

int main() {
    ifstream fin("test.in");
    ll n, d, a, b;
    fin >> n >> d >> a >> b;
    vector<ll> bottles(n);
    for(int i = 0; i < n; i++) {
        fin >> bottles[i];
    }
    sort(bottles.begin(), bottles.end());
    int start = n-a;
    int end = n-b-1;
    int bend = end+1;
    while(bend+1 < n && bottles[bend+1] == bottles[bend]) bend++;
    int bstart = end+1;
    int overlap = 0;
    while(bstart < n && bstart-1 >= start && bottles[bstart-1] == bottles[bstart]) {
        bstart--;
        overlap++;
    }
    ll bmin = LLONG_MAX;
    int nummin = 0;
    if(bstart < n) {
        nummin = bend-bstart+1;
        bmin = bottles[bstart];
    }

    for(int i = 1; i <= d; i++) {
        // automatically keep track of value of all elements to left of border
        // incrementing (overlap) elements in the border
        if(nummin > overlap) {
            nummin -= overlap;
        }
        else {
            ll difference = overlap - nummin;
            nummin = bend-bstart+1 - difference;
            bmin++;
        }
        // expand border to the left
        if(bstart < n) {
            while(bstart-1 >= start && bottles[bstart-1]+i >= bmin) {
                bstart--;
                nummin += bottles[bstart] + i == bmin;
                overlap++;
            }
        }
        // expand border to the right
        while(bend+1 < n && bottles[bend+1] <= bmin) {
            bend++;
            nummin += bottles[bend] == bmin;
        }
        cout << "after day: " << i << " border start: " << bstart << " border end: " << bend << " min number: " << bmin << " number of mins: " << nummin << " overlap: " << overlap << endl;
    }
    ll answer = 0;
    for(int i = 0; i < n; i++) {
        if(i < start || i > bend) {
            answer += ((bottles[i]%MOD) * (bottles[i]%MOD))%MOD;
        }
        else if(bstart >= n) {
            answer += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD))%MOD;
        }
        else if(i < bstart) {
            cout << i << endl;
            answer += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD))%MOD;
        }
        answer %= MOD;
    }
    ll test = 0;
    for(int i = 0; i < n; i++) {
        if(i < start || i > end) {
            cout << i << "|" << endl;
            test += ((bottles[i]%MOD) * (bottles[i]%MOD))%MOD;
            test %= MOD;
        }
        if(i >= start && i <= end) {
            cout << i << endl;
            test += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD)%MOD);
            test %= MOD;
        }
    }
    cout << test << endl;
    if(bstart < n) answer += ((nummin%MOD*bmin%MOD*bmin%MOD)%MOD + ((bend-bstart+1-nummin)%MOD*(bmin+1)%MOD*(bmin+1)%MOD)%MOD)%MOD;
    answer %= MOD;
    cout << answer << endl;
    //for(int i = 0; i < n; i++) cout << i << " " << bottles[i] << endl;
}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <fstream>
//#define ll long long
//using namespace std;
//
//const ll MOD = 1e9+7;
//
//int main() {
//    ifstream fin("test.in");
//    ll n, d, a, b;
//    fin >> n >> d >> a >> b;
//    vector<ll> bottles(n);
//    for(int i = 0; i < n; i++) {
//        fin >> bottles[i];
//    }
//    fin.close();
//    sort(bottles.begin(), bottles.end());
//    int start = n-a;
//    int end = n-b-1;
//    int bend = end+1;
//    while(bend+1 < n && bottles[bend+1] == bottles[bend]) bend++;
//    int bstart = end+1;
//    int overlap = 0;
//    while(bstart < n && bstart-1 >= start && bottles[bstart-1] == bottles[bstart]) {
//        bstart--;
//        overlap++;
//    }
//    ll bmin = LLONG_MAX;
//    ll nummin = 0;
//    if(bstart < n) {
//        nummin = bend-bstart+1;
//        bmin = bottles[bstart];
//    }
//
//    ll i = 1;
//    double add;
//    while(i <= d) {
//        cout << i << endl;
//        // increment i until the next border expansion
//        if(bstart >= n) continue;
//        if(i == d) break;
//        add = d-i;
//        if(bend+1 < n) add = min(add, ceil(((bottles[bend+1] - bmin) * (bend - bstart + 1) - (bend - bstart + 1 - nummin))/overlap));
//        if(bstart-1 >= start) add = min(add, floor(((bmin - bottles[bstart-1] - i) * (bend - bstart + 1) + (bend - bstart + 1 - nummin))/((bend - bstart + 1) - overlap)));
////        cout << "after day: " << i << " border start: " << bstart << " border end: " << bend << " min number: " << bmin << " number of mins: " << nummin << " overlap: " << overlap << endl;
//        cout << ((bottles[bend+1] - bmin) * (bend - bstart + 1) - (bend - bstart + 1 - nummin)) << " " << overlap << endl;
//        i += add;
//        // automatically keep track of value of all elements to left of border
//        // incrementing (overlap) elements in the border
////        cout << nummin << " " << add << " " << bmin << endl;
//
//        if(add*overlap >= nummin) {
//            ll toadd = add*overlap-nummin;
//            nummin = bend-bstart+1;
//            bmin++;
//
//            bmin += toadd/(bend-bstart+1);
//            nummin -= toadd%(bend-bstart+1);
//        }
//        else {
//            nummin -= add*overlap;
//        }
//        // expand border to the left
//        if(bstart < n) {
//            while(bstart-1 >= start && bottles[bstart-1]+i >= bmin) {
//                bstart--;
//                nummin += bottles[bstart] + i == bmin;
//                overlap++;
//            }
//        }
//        // expand border to the right
//        while(bend+1 < n && bottles[bend+1] <= bmin+1) {
//            bend++;
//            nummin += bottles[bend] == bmin;
//        }
//    }
////    cout << "after day: " << i << " border start: " << bstart << " border end: " << bend << " min number: " << bmin << " number of mins: " << nummin << " overlap: " << overlap << endl;
//    ll answer = 0;
//    for(int i = 0; i < n; i++) {
//        if(i < start || i > bend) {
//            answer += ((bottles[i]%MOD) * (bottles[i]%MOD))%MOD;
//        }
//        else if(bstart >= n) {
//            answer += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD))%MOD;
//        }
//        else if(i < bstart) {
//            answer += (((bottles[i]+d)%MOD) * ((bottles[i]+d)%MOD))%MOD;
//        }
//        answer %= MOD;
//    }
//    if(bstart < n) answer += ((nummin%MOD*bmin%MOD*bmin%MOD)%MOD + ((bend-bstart+1-nummin)%MOD*(bmin+1)%MOD*(bmin+1)%MOD)%MOD)%MOD;
//    answer %= MOD;
//    cout << answer << endl;
//}
