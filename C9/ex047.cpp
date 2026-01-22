#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector<int> adj[MAXN];
int match[MAXN];
bool visited[MAXN];
int n, m;

bool dfs(int u)
{
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        visited[v] = true;

        if (match[v] == -1 || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool solve()
{
    memset(match, -1, sizeof(match));

    int matched = 0;

    for (int u = 0; u < n; u++)
    {
        memset(visited, false, sizeof(visited));
        if (dfs(u))
        {
            matched++;
        }
    }

    return matched == n;
}

int main()
{
    int c;
    cin >> c;

    while (c--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
        }

        if (solve())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}