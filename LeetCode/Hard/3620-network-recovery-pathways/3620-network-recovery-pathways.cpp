class Solution {
public:
    using ll = long long;

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            indegree[v]++;
            maxCost = max(maxCost, w);
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &edge : graph[u]) {
                int v = edge.first;
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) -> bool {
            const ll INF = (1LL << 60);

            vector<ll> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF)
                    continue;

                // Intermediate offline nodes are not allowed
                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &edge : graph[u]) {
                    int v = edge.first;
                    int w = edge.second;

                    if (w < limit)
                        continue;

                    if (v != 0 && v != n - 1 && !online[v])
                        continue;

                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0, hi = maxCost;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};