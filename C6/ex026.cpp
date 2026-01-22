#include <bits/stdc++.h>

using namespace std;

long long harmony(const vector<long long> &A, const vector<long long> &B)
{
    int n = A.size();
    int m = B.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, -1e18));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            long long prod = A[i - 1] * B[j - 1];

            dp[i][j] = max({prod, dp[i - 1][j - 1] + prod, dp[i - 1][j], dp[i][j - 1]});
        }
    }

    return dp[n][m];
}

int main()
{

    int n, m;

    cin >> n;
    vector<long long> A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> m;

    vector<long long> B(m);
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    cout << harmony(A, B) << endl;

    return 0;
}