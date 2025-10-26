#include <queue>
#include <vector>
#include <algorithm>

class Solution {
public:
    // implement sparse tree
    const int LOG = 15;
    const int N  = 20001;
    int st[20001][15];

    int query(int l, int r) {
        int length = r-l+1;
        int exp = 0;
        while((1<<(exp+1)) <= length) {
            exp++;
        }
        return max(st[l][exp], st[r-(1<<exp)+1][exp]);
    }

    int trap(vector<int>& height) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> order;
        // base case: 1 intervals
        for(int i = 0; i < height.size(); i++) {
            st[i][0] = height[i];
        }
        for(int i = 1; i < LOG; i++) {
            for(int j = 0; j + (1<<i)-1 < height.size(); j++) {
                st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
            }
        }
        int total = 0;
        for(int i = 0; i < height.size(); i++) {
            // if(height[i] == 0) continue;
            // any tower less than the current one is now useless
            int highestReached = 0;
            while(!order.empty() && order.top().first <=  height[i]) {
                // case where towers next to each other
                highestReached = max(highestReached, order.top().first);
                if(order.top().second+1 == i) {
                    order.pop();
                    continue;
                }
                auto next = order.top();
                order.pop();
                int subtract = query(next.second+1, i-1);
                total += (min(next.first, height[i])-subtract)*(i-next.second-1);
            }
            if(!order.empty() && highestReached < height[i] && order.top().second+1 != i) {
                auto next = order.top();
                order.pop();
                int subtract = query(next.second+1, i-1);
                total += (min(next.first, height[i])-subtract)*(i-next.second-1);
                order.push(next);
            }
            order.push({height[i], i});
        }
        return total;
    }
};
