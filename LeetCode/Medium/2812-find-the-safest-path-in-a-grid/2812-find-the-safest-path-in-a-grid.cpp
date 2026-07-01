#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Step 1: multi-source BFS from thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: max heap for best path
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) return safe;

            if (safe < best[r][c]) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int nsafe = min(safe, dist[nr][nc]);

                    if (nsafe > best[nr][nc]) {
                        best[nr][nc] = nsafe;
                        pq.push({nsafe, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};