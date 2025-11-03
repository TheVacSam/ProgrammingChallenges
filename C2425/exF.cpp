#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

int main()
{
    int n, q;
    cin >> n >> q;

    // Pré-computar os valores de dp
    // dp[i] = número de caminhos para alcançar o andar i
    // sum[i] = soma total de figurinos em todos os caminhos até o andar i
    vector<long long> paths(n + 1, 0);
    vector<long long> totalFigurines(n + 1, 0);

    paths[1] = 1;
    totalFigurines[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        // Pode vir do andar i-1 (1 escada)
        paths[i] = paths[i - 1];
        totalFigurines[i] = (totalFigurines[i - 1] + paths[i - 1]) % MOD;

        // Pode vir do andar i-2 (2 escadas)
        if (i >= 2)
        {
            paths[i] = (paths[i] + paths[i - 2]) % MOD;
            totalFigurines[i] = (totalFigurines[i] + totalFigurines[i - 2] + paths[i - 2]) % MOD;
        }
    }

    // Processar queries
    for (int i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;

        if (s == t)
        {
            cout << 0 << endl;
            continue;
        }

        // Recomputar para o intervalo específico
        int dist = t - s;
        vector<long long> dp_paths(dist + 1, 0);
        vector<long long> dp_sum(dist + 1, 0);

        dp_paths[0] = 1;
        dp_sum[0] = 0;

        for (int j = 1; j <= dist; j++)
        {
            // Vem de j-1
            dp_paths[j] = dp_paths[j - 1];
            dp_sum[j] = (dp_sum[j - 1] + dp_paths[j - 1]) % MOD;

            // Vem de j-2
            if (j >= 2)
            {
                dp_paths[j] = (dp_paths[j] + dp_paths[j - 2]) % MOD;
                dp_sum[j] = (dp_sum[j] + dp_sum[j - 2] + dp_paths[j - 2]) % MOD;
            }
        }

        cout << dp_sum[dist] << endl;
    }

    return 0;
}
