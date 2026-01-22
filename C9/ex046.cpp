#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int a, b;
    long long cost;
};

const long long INF = 1e18;

vector<bool> bfs_reachable(int start, const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> reachable(n, false);
    queue<int> q;
    q.push(start);
    reachable[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (!reachable[v])
            {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    return reachable;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> reverse_graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x});

        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    vector<bool> reachable = bfs_reachable(1, graph);

    vector<bool> reach = bfs_reachable(n, reverse_graph);

    vector<long long> d(n + 1, INF);
    d[1] = 0;
    int x = -1;

    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (const Edge &e : edges)
        {
            if (d[e.a] < INF)
            {
                if (d[e.b] > d[e.a] + e.cost)
                {
                    d[e.b] = max(-INF, d[e.a] + e.cost);
                    x = e.b;
                }
            }
        }
    }

    if (x != -1)
    {
        vector<bool> cycle(n + 1, false);
        cycle[x] = true;

        for (int i = 0; i < n; ++i)
        {
            for (const Edge &e : edges)
            {
                if (d[e.a] < INF && d[e.b] > d[e.a] + e.cost)
                {
                    d[e.b] = d[e.a] + e.cost;
                    cycle[e.b] = true;
                }
                if (cycle[e.a])
                {
                    cycle[e.b] = true;
                }
            }
        }

        bool problem = false;
        for (int i = 1; i <= n; i++)
        {
            if (cycle[i] && reachable[i] && reach[i])
            {
                problem = true;
                break;
            }
        }

        if (problem)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << -d[n] << endl;

    return 0;
}