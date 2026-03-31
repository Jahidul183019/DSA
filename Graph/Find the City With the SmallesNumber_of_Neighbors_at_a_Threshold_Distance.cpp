// Leetcode 1334

class Solution
{
public:
    class Edge
    {
    public:
        int v;
        int wt;

        Edge(int v, int wt)
        {
            this->v = v;
            this->wt = wt;
        }
    };
    vector<int> dijkstra(int src, vector<vector<Edge>> &g, int V)
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (Edge e : g[u])
            {
                if (dist[e.v] > d + e.wt)
                {
                    dist[e.v] = d + e.wt;
                    pq.push({dist[e.v], e.v});
                }
            }
        }

        return dist;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<Edge>> g(n);

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];

            g[u].push_back(Edge(v, w));
            g[v].push_back(Edge(u, w));
        }

        int bestCity = -1;
        int bestCount = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            vector<int> dist = dijkstra(i, g, n);

            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[j] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if (cnt < bestCount || (cnt == bestCount && i > bestCity))
            {
                bestCity = i;
                bestCount = cnt;
            }
        }
        return bestCity;
    }
};