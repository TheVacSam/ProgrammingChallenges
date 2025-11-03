/*
Temos primeiro x casos teste (que so acabam quando é dado um 0)
Cada caso vai ter respetivamente n froshs diferentes
Cada frosh tem 5 courses diferentes escolhidos pelo proprio
O course number é dado por um inteiro entre 100 e 499


Complexidade temporal O(n log(n))
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    while (n != 0)
    {
        map<set<int>, int> frosh;

        for (int i = 0; i < n; i++)
        {

            set<int> conj;
            for (int j = 0; j < 5; j++)
            {
                int courses;
                cin >> courses;
                conj.insert(courses);
            }

            frosh[conj]++;
        }

        int popularity = 0;
        for (auto x : frosh)
        {
            if (x.second >= popularity)
            {
                popularity = x.second;
            }
        }

        int sump = 0;
        for (auto x : frosh)
        {
            if (x.second == popularity)
            {
                sump += x.second;
            }
        }

        cin >> n;
        cout << sump << endl;
    }

    return 0;
}