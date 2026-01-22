#include <bits/stdc++.h>
using namespace std;

int palindrome()
{
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len)
    {
        for (int i = 0; i <= n - len; ++i)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int t;
    if (cin >> t)
    {
        for (int i = 1; i <= t; ++i)
        {
            cout << palindrome() << endl;
        }
    }
    return 0;
}
