/*
Fabrica tem n maquinas que podem ser usada para produção
O objetivo é fazer um total de t produtos

Para cada maquina sabemos o numero de segundos precisos
para fazer um produto
As maquinhas podem trabalhar em simultaneo e posso decidir
o horario em que trabalho sob a minha vontade

Qual é que é então o Shortest time preciso para fazer t produtos??

1st input line tem 2 inteiros n e t
A seguinte linha tem nn inteiros k...kn (tempo necessario para fazer 1 produto)

In
3 7
3 2 5

Out
8
*/

#include <bits/stdc++.h>
using namespace std;

bool produce(vector<long> v, long t, long time)
{
    long total = 0;

    for (int i = 0; i < v.size(); i++)
    {
        total += time / v[i];

        if (total >= t)
        {
            return true;
        }
    }
    return total >= t;
}

int main()
{
    int n;
    long t;
    cin >> n >> t;

    vector<long> v(n);
    long mintime = LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mintime = min(mintime, v[i]);
    }

    long left = 1;
    long right = mintime * t;
    long answer = right;

    while (left <= right)
    {
        long mid = left + (right - left) / 2;

        if (produce(v, t, mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}

// imagina, posso ter uma maquina a fazer 4/7(2s) e outra 2/7(3s) e outra 1/7(5s)