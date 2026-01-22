#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void bfs(int sr, int sc, vector<vector<int>> &bank, vector<string> &grid, int id)
{
    int R = grid.size();
    int C = grid[0].size();

    queue<pair<int, int>> q;

    q.push({sr, sc});
    bank[sr][sc] = id;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == '#' && bank[nr][nc] == 0)
            {
                bank[nr][nc] = id;
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    int R, C, B, S;
    cin >> R >> C >> B >> S;

    vector<string> grid(R);
    for (int i = 0; i < R; i++)
        cin >> grid[i];

    vector<vector<int>> bank(R, vector<int>(C, 0));
    for (int c = 0; c < C; c++)
    {
        if (grid[0][c] == '#' && bank[0][c] == 0)
            bfs(0, c, bank, grid, 1);
        if (grid[R - 1][c] == '#' && bank[R - 1][c] == 0)
            bfs(R - 1, c, bank, grid, 2);
    }

    vector<int> len(C, INF);
    for (int c = 0; c < C; c++)
    {
        int n = -1;
        int s = R;
        for (int r = 0; r < R; r++)
        {
            if (bank[r][c] == 1)
                n = max(n, r);

            if (bank[r][c] == 2)
                s = min(s, r);
        }

        if (n >= 0 && s < R && n < s)
            len[c] = s - n - 1;
    }

    vector<vector<int>> dp(C, vector<int>(B + 1, INF));

    for (int c = 0; c < C; c++)
        if (len[c] < INF)
            dp[c][1] = len[c];

    for (int c = 0; c < C; c++)
    {
        if (len[c] >= INF)
            continue;

        for (int b = 2; b <= B; b++)
        {
            for (int pc = 0; pc <= c - S - 1; pc++)
            {
                if (dp[pc][b - 1] < INF)
                {
                    dp[c][b] = min(dp[c][b], dp[pc][b - 1] + len[c]);
                }
            }
        }
    }

    int ans = INF;

    for (int c = 0; c < C; c++)
    {
        ans = min(ans, dp[c][B]);
    }

    cout << ans << endl;

    return 0;
}
