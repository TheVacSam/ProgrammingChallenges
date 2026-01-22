#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int R, int C, queue<pair<int, int>> &q, vector<vector<int>> &dist)
{
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // Verificar limites e se já foi visitado
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    int R, C;

    cin >> R >> C;

    vector<string> grid(R);
    queue<pair<int, int>> q;
    vector<vector<int>> dist(R, vector<int>(C, -1));
    vector<pair<int, int>> airports;

    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '#')
            {
                q.push({i, j});
                dist[i][j] = 0; // Nuvens começam no dia 0
            }
            if (grid[i][j] == 'A')
            {
                airports.push_back({i, j});
            }
        }
    }

    bfs(R, C, q, dist);

    int Nmin = INT_MAX;
    int Nmax = INT_MIN;

    for (auto [x, y] : airports)
    {
        int days = dist[x][y];
        Nmin = min(Nmin, days);
        Nmax = max(Nmax, days);
    }

    cout << Nmin << " " << Nmax << endl;

    return 0;
}