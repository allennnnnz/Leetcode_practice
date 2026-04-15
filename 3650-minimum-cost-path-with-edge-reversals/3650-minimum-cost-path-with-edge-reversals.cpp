class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        // Build graph:
        // original: u->v cost w
        // switch-reverse option when at v: v->u cost 2w
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        const long long INF = (1LL<<62);
        vector<long long> dist(n, INF);
        dist[0] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;   // outdated state
            if (u == n - 1) break;        // optional early stop

            for (auto &[v, w] : adj[u]) {
                long long nd = d + (long long)w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        if (dist[n-1] == INF) return -1;
        return (dist[n-1] > (long long)INT_MAX) ? (int)dist[n-1] : (int)dist[n-1];
    }
};