#include <bits/stdc++.h>
using namespace std;

int n, A, B;
vector<int> limit;
map<pair<int, int>, int> dp;

int solve(int pos, int vel)
{
    if (pos > n)
        return 0;

    auto state = make_pair(pos, vel);
    if (dp.count(state))
        return dp[state];

    int best = INT_MAX;

    for (int dv = -B; dv <= A; dv += 10)
    {
        int newV = vel + dv;

        if (newV < 0)
            continue;

        int units = newV / 10;

        if (units == 0)
            continue;

        bool valid = true;
        for (int i = 1; i <= units; i++)
        {
            int idx = pos + i;

            if (idx > n)
                break;

            if (limit[idx - 1] < newV)
            {
                valid = false;
                break;
            }
        }

        if (!valid)
            continue;

        int nextPos = pos + units;

        if (nextPos > n)
        {
            best = min(best, 1);
        }
        else
        {
            int subResult = solve(nextPos, newV);
            if (subResult != -1)
                best = min(best, 1 + subResult);
        }
    }

    int result = (best == INT_MAX) ? -1 : best;
    dp[state] = result;
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> A >> B;

        limit.clear();
        int d, v;

        while (cin >> d >> v && (d || v))
        {
            for (int i = 0; i < d; i++)
            {
                limit.push_back(v);
            }
        }

        if (limit.empty())
        {
            cout << 0 << '\n';
            continue;
        }

        n = limit.size();
        dp.clear();

        int result = solve(0, 0);
        cout << result << '\n';
    }

    return 0;
}