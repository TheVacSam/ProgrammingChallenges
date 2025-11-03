/*
Recebemos dois inteiros, que representam o tamanho da estrada e o numero de semaforos
Depois vamos ter a posicao de cada semaforo, a cada adicao, vamos retornar a maior distancia percorrida sem apanhar semaforos

O ideal é começar por usar um set com as posicoes dos semaforos (fica ordenado e sem repetiçoes)
Um multiset para guardar o comprimento da estrada a percorrer ss (permite repetiçoes)
Inserir o inicio (0) e o fim (x) da estrada
Comprimento é x inicialmente

Para cada posição (p) usamos o upper_bound para retornar o primeiro elemento maior que p
E o prev, para encontrar o elemento anterior onde p sera inserido

Identificamos entao o segmento [left, right] que será dividido ao inserir p
Removemos o comprimento antigo (right - left) do multiset
Inserimos os dois novos comprimentos
Adicionamos p ao set das posições dos semaforos

Retornar o maior comprimento atual com length.rbegin() (Return reverse iterator to reverse beginning)

Complexidade temporal -> O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x, n;
    cin >> x >> n;

    set<int> tl;
    multiset<int> length;

    tl.insert(0);
    tl.insert(x);
    length.insert(x);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        auto right = tl.upper_bound(p);
        auto left = prev(right);

        length.erase(length.find(*right - *left));

        length.insert(p - *left);
        length.insert(*right - p);

        tl.insert(p);

        cout << *length.rbegin() << " ";
    }

    cout << endl;
    return 0;
}