#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    long long x, y, n;
    cin >> x >> y >> n;

    vector<pair<long long, long long>> route(n);
    for (int i = 0; i < n; i++)
    {
        cin >> route[i].first >> route[i].second;
    }

    // Calcular a distância mínima de Stan até cada posição na rota de Roger
    double minTime = 1e18;

    for (int i = 0; i < n; i++)
    {
        // Distância Manhattan de Stan até a posição i
        long long dist = abs(x - route[i].first) + abs(y - route[i].second);

        // Roger pode estar em qualquer posição do ciclo
        // Tempo para Stan alcançar esta posição
        double time = dist;

        // Verificar se há encontro no meio do caminho
        // Quando movem um em direção ao outro
        if (i > 0)
        {
            // Verificar posição anterior
            long long px = route[i - 1].first;
            long long py = route[i - 1].second;
            long long distPrev = abs(x - px) + abs(y - py);

            // Se forem vizinhos e se moverem um para o outro, encontram em 0.5s
            if (abs(route[i].first - px) + abs(route[i].second - py) == 1)
            {
                if (distPrev < time)
                {
                    time = min(time, (double)distPrev + 0.5);
                }
            }
        }

        minTime = min(minTime, time);
    }

    // Calcular tempo esperado
    // Stan deve usar a estratégia ótima: ir para o ponto mais próximo
    double expectedTime = 0;

    for (int i = 0; i < n; i++)
    {
        long long dist = abs(x - route[i].first) + abs(y - route[i].second);
        expectedTime += dist;
    }

    expectedTime /= n;

    cout << fixed << setprecision(2) << expectedTime << endl;

    return 0;
}
