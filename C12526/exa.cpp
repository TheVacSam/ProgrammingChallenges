/*
Temos um wild Kangaroo a saltar numa propriedade
O kangaroo começa na posicao 0
A ideia é ver o quao longe o kangaroo consegue chegar apos um x numero de saltos

Os saltos do kangoroo têm um comportamento especifico:
1o salto salta A unidades para a direita (x+A)
2o salto "" B unidades para a esquerda (x-B)
3o salto "" A unidades para a direita outra vez (x+A)
4o salto "" B unidades para a esquerda
E por ai em diante alternando entre direita, esquerda, direita ...

Os rapazes fazem T observaçoes de como o kangaroo se moveu apos K saltos
dado os comprimentos de salto A e B

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int pos = 0;
        int a, b, k;
        cin >> a >> b >> k;

        int sd = k / 2;
        pos = sd * (a - b);

        if (k % 2 == 1)
        {
            pos += a;
        }

        cout << pos << endl;
    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    list<string> chats;
    unordered_map<string, list<string>::iterator> chatMap;
    
    for (int i = 0; i < n; i++)
    {
        string m;
        cin >> m;
        
        auto it = chatMap.find(m);
        if (it != chatMap.end())
        {
            chats.erase(it->second);  // O(1)!
        }
        
        chats.push_back(m);
        chatMap[m] = --chats.end();
    }
    
    reverse(chats.begin(), chats.end());
    
    for (const string& chat : chats)
    {
        cout << chat << "\n";
    }
    
    return 0;
}
*/