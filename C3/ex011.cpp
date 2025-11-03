/*
Vou ter um array com n inteiros
O objetivo é ordenar o array de maneira descendente,
de  acordo com a quantidade  de 1's que o respetivo numero
tem na forma binaria
Se dois numeros tiverem o mesmo numero de 1's tenho que os ordenar
de maneira ascendente pelo valor mais alto
*/

#include <bits/stdc++.h>
using namespace std;

// recursive function to count set bits (GEEKSFORGEEKS)
int countSetBits(int n)
{
    // base case
    if (n == 0)
        return 0;
    else
        // if last bit set add 1 else add 0
        return (n & 1) + countSetBits(n >> 1);
}

bool compareNumbers(int a, int b)
{

    int countA = countSetBits(a);
    int countB = countSetBits(b);

    if (countA != countB)
    {
        return countA > countB; // True se A tiver maior numero de bits e vv
    }

    return a < b; // desempate por valor de a e b
};

int main()
{
    int n;
    cin >> n;

    vector<int> seq(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    // sort(v, v+n, comparePerson);
    sort(seq.begin(), seq.end(), compareNumbers);

    for (int i = 0; i < n; i++)
    {
        cout << seq[i];

        if (i < n - 1)
        {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}