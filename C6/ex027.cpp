#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int dp[105][105];

int cores[105];

int cor(int a, int b)
{
    int soma = 0;

    for (int i = a; i <= b; i++)
    {
        soma = (soma + cores[i]) % 100;
    }
    return soma;
}

void matrixchain(int n)
{
    // int n = p.size() - 1;

    // vector<vector<int>> m(n + 1, vector<int>(n + 1));

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0; // caso base
    }

    for (int l = 2; l <= n; l++)
    {

        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1; // j é o índice de fim da cadeia

            dp[i][j] = INF; // Inicializamos com valor máximo

            // k é o ponto de corte entre as matrizes i e j
            for (int k = i; k <= j - 1; k++)
            {

                long long fumo = cor(i, k) * cor(k + 1, j);

                long long custo = dp[i][k] + dp[k + 1][j] + fumo;

                if (custo < dp[i][j])
                {
                    dp[i][j] = custo;
                }
            }
        }
    }
    // return dp[1][n];
    cout << dp[0][n - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t)
    {
        while (t--)
        {
            int n;
            if (!(cin >> n))
                break;

            for (int j = 0; j < n; j++)
            {
                cin >> cores[j];
            }

            matrixchain(n);
        }
    }
    return 0;
}