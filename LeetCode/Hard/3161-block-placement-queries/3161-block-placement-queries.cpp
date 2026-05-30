#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct SegTree {
        int n;
        vector<int> tree;
        SegTree(int n) : n(n), tree(2 * n, 0) {}
        
        void update(int pos, int val) {
            pos += n;
            tree[pos] = val;
            for (pos >>= 1; pos >= 1; pos >>= 1)
                tree[pos] = max(tree[2*pos], tree[2*pos+1]);
        }
        
        int query(int l, int r) {
            int res = 0;
            for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, tree[l++]);
                if (r & 1) res = max(res, tree[--r]);
            }
            return res;
        }
    };

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXV = 50001;
        
        set<int> obs;
        obs.insert(0);
        obs.insert(MAXV);
        
        SegTree seg(MAXV + 1);
        seg.update(MAXV, MAXV);
        
        vector<bool> results;
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                
                auto it = obs.upper_bound(x);
                int R = *it;
                int L = *prev(it);
                
                seg.update(R, 0);
                seg.update(x, x - L);
                seg.update(R, R - x);
                
                obs.insert(x);
                
            } else {
                int x = q[1], sz = q[2];
                
                auto it = obs.upper_bound(x);
                int L = *prev(it);
                
                int partial = x - L;
                
                int maxGap = (L > 0) ? seg.query(1, L) : 0;
                maxGap = max(maxGap, partial);
                
                results.push_back(maxGap >= sz);
            }
        }
        
        return results;
    }
};