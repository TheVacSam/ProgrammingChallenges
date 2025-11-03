#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int maxlength = 0;
    int prev = 0;

    map<int, int> last; // dicionario com as ultimas posiçoes

    for (int i = 0; i < n; i++)
    {
        int s;
        cin >> s;

        if (last.count(s)) // verificar se ja esta no dicionario
        {
            prev = max(prev, last[s] + 1);
        }

        last[s] = i;
        maxlength = max(maxlength, i - prev + 1);
    }

    cout << maxlength << endl;
    return 0;
}

// complexidade O(n) no pior caso