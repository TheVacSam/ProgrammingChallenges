#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<int> portas(n);

        for (int i = 0; i < n; i++)
        {
            cin >> portas[i];
        }

        bool button = false;
        int trestante = 0;
        bool passa = true;

        for (int i = 0; i < n; i++)
        {
            if (portas[i] == 1 && !button)
            {
                button = true;
                trestante = x;
            }

            if (portas[i] == 1 && trestante <= 0)
            {
                passa = false;
                break;
            }

            if (button && trestante > 0)
            {
                trestante--;
            }
        }

        if (passa)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}