#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    // Ordenar as alturas em ordem crescente
    sort(heights.begin(), heights.end());

    // Multiset para guardar a altura da pessoa no topo de cada coluna
    multiset<int> columns;

    // Processar cada pessoa por ordem crescente de altura
    for (int i = 0; i < n; i++)
    {
        int current_height = heights[i];

        // Procurar uma coluna onde o topo seja <= altura atual
        auto it = columns.upper_bound(current_height);

        if (it != columns.begin())
        {
            // Encontrámos uma coluna válida
            it--;
            columns.erase(it);
            columns.insert(current_height);
        }
        else
        {
            // Não há coluna válida, criar nova coluna
            if (columns.size() < w)
            {
                columns.insert(current_height);
            }
            else
            {
                // Impossível arranjar - já temos w colunas e nenhuma é válida
                cout << "no" << endl;
                return 0;
            }
        }
    }

    cout << "yes" << endl;
    return 0;
}
