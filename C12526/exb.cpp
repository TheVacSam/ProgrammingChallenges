/*
Decidiram comparar qual deles era o mais influente da cidade
C-Index é o maior numero (C) tal que a pessoa tenha pelo menos C videos,
com C ou > views

ExKyle has made 10 videos and each one has at least 10 views,
his C-Index is at least 10 (which really annoys Cartman).



*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    int c = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<>());

    for (int i = 0; i < n; i++)
    {
        // cout << v[i] << endl;

        if (v[i] >= n || v[i] > c)
        {
            c++;
        }
    }
    cout << c << endl;

    return 0;
}



/*
import java.util.*;

public class contest3 {
    //Como não é por frequência e sim o ultimo a falar, pode ser LinkedList?? ou ArrayList ou circular linked list??
    // não deu certo nem com apoio do hashset, vou fazer com um linledhashset
    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        LinkedHashSet<String> teste2 = new LinkedHashSet<>();
        
        for (int i = 0; i < n; i++) {
            String amigo = scanner.next();
            teste2.remove(amigo);
            teste2.add(amigo);
        }
        // Como  não há addFirst agora tenho de inverter e ver se dá certo
        List<String> lista_resultado = new ArrayList<>(teste2);
        Collections.reverse(lista_resultado);
        for (String amigo : lista_resultado) {
            System.out.println(amigo);
        }
    }
}
*/