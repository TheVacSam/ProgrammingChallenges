/*
Dados n edificos com alturas h...hn
Vamos ter como objetivo fazer com que cada edifico tenha a mesma altura
Podemos fazer isso adicionando ou removendo alguns tijolos do edificio
Remover ou adicionar algum tijolo tera um certo custo
que vai depender da altura do edificio
O objetivo principal sera encontrar o custo minimo
em que e possivel reconstruir os edificios de maneira a que
os N edificios fiquem com as mesma altura

Por conveniencias todos os edf sao considerados pilares verticais de tijolos com a mesma dimensao

*/

#include <bits/stdc++.h>
using namespace std;

long cost(int n, vector<long> h, vector<long> c, long k)
{
    long total = 0;
    for (int i = 0; i < n; i++)
    {
        total += c[i] * abs(h[i] - k);
    }
    return total;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long> h(n), c(n);

        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        long left = 0;
        long right = 10000;

        while (right - left > 2)
        {
            long m1 = left + (right - left) / 3;
            long m2 = right - (right - left) / 3;

            if (cost(n, h, c, m1) > cost(n, h, c, m2))
            {
                left = m1;
            }
            else
            {
                right = m2;
            }
        }

        long minCost = LLONG_MAX;
        for (long k = left; k <= right; k++)
        {
            minCost = min(minCost, cost(n, h, c, k));
        }

        cout << minCost << endl;
    }

    return 0;
}
