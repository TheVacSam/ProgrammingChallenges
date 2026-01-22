#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, -INF);
    p.assign(n, -1);

    d[s] = INF;
    typedef pair<int, int> pii;
    priority_queue<pii> q;
    q.push(make_pair(INF, s));

    while (!q.empty())
    {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if (d_v != d[v])
            continue;

        for (int i = 0; i < adj[v].size(); i++)
        {
            int to = adj[v][i].first;
            int len = adj[v][i].second;

            int new_val = min(d[v], len);

            if (new_val > d[to])
            {
                d[to] = new_val;
                p[to] = v;
                q.push(make_pair(d[to], to));
            }
        }
    }
}

int main()
{
    int n, e, k;
    cin >> n >> e;

    struct Edge
    {
        int a, b, v;
    };
    vector<Edge> edges;

    for (int i = 0; i < e; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        Edge edge;
        edge.a = a;
        edge.b = b;
        edge.v = v;
        edges.push_back(edge);
    }

    cin >> k;

    int total_nodes = n * (k + 1);
    adj.resize(total_nodes);

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int v = edges[i].v;

        for (int r = 0; r <= k; r++)
        {
            int node_a = a * (k + 1) + r;
            int node_b = b * (k + 1) + r;

            adj[node_a].push_back(make_pair(node_b, v));
            adj[node_b].push_back(make_pair(node_a, v));

            if (r < k)
            {
                int node_a_next = a * (k + 1) + (r + 1);
                int node_b_next = b * (k + 1) + (r + 1);

                adj[node_a].push_back(make_pair(node_b_next, 2 * v));
                adj[node_b].push_back(make_pair(node_a_next, 2 * v));
            }
        }
    }

    vector<int> d, p;
    int start = 0 * (k + 1) + 0;
    dijkstra(start, d, p);

    int best = -INF;
    for (int r = 0; r <= k; r++)
    {
        int dest_node = (n - 1) * (k + 1) + r;
        best = max(best, d[dest_node]);
    }

    cout << best << endl;

    return 0;
}