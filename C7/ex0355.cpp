#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> memo;

long long encode(const vector<int> &h)
{
    long long mask = 0;
    for (int i = 0; i < h.size(); ++i)
    {
        mask |= ((long long)h[i] << (i * 4));
    }
    return mask;
}

int solve(vector<int> h)
{
    long long mask = encode(h);

    if (memo.count(mask))
        return memo[mask];

    bool onlyP = true;
    if (h[0] != 1)
        onlyP = false;
    for (size_t i = 1; i < h.size(); ++i)
    {
        if (h[i] > 0)
        {
            onlyP = false;
            break;
        }
    }

    if (onlyP)
    {
        return memo[mask] = 2;
    }

    for (int c = 0; c < 10; ++c)
    {
        for (int r = 0; r < h[c]; ++r)
        {
            if (c == 0 && r == 0)
                continue;

            vector<int> next_h = h;
            bool changed = false;

            for (int k = c; k < 10; ++k)
            {
                if (next_h[k] > r)
                {
                    next_h[k] = r;
                    changed = true;
                }
            }

            if (solve(next_h) == 2)
            {
                return memo[mask] = 1;
            }
        }
    }

    return memo[mask] = 2;
}

void solve_case(int caseNum)
{
    int R, C;
    cin >> R >> C;

    vector<string> grid(R);
    vector<int> h(10, 0);

    for (int i = 0; i < R; ++i)
    {
        cin >> grid[i];
    }

    for (int j = 0; j < C; ++j)
    {
        int count = 0;
        for (int i = 0; i < R; ++i)
        {
            if (grid[i][j] != '.')
            {
                count++;
            }
        }
        h[j] = count;
    }

    int result = solve(h);

    cout << "Case #" << caseNum << ": ";
    if (result == 1)
        cout << "winning position" << endl;
    else
        cout << "losing position" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    if (cin >> N)
    {
        for (int i = 1; i <= N; ++i)
        {
            solve_case(i);
        }
    }
    return 0;
}