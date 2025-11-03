/*
Nova app chat, mostra a lista de conversas
Quando manda uma mensagem a um amigo vamos ter:
    Se nunca conversou com ele, é add uma nova entrada no topo da lista
    Se ja tiver conversado com ele, esse chat sobe para o topo e os outros mantem a ordem

Assumindo chat list = empty inicialmente
Apos todas as mensagem serem enviadas, o eric quer saber a ordem em
que aparecem os chats, do topo(mais recente) até baixo(mais antigo)

voltar à logica inicial do multiset, so que com uma lista e um map

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    list<string> c;
    unordered_map<string, list<string>::iterator> s;

    for (int i = 0; i < n; i++)
    {
        string m;
        cin >> m;

        auto it = s.find(m);

        if (it != s.end())
        {
            c.erase(s[m]);
        }

        c.push_front(m);
        s[m] = c.begin();
    }

    for (auto x : c)
    {
        cout << x << endl;
    }

    return 0;
}