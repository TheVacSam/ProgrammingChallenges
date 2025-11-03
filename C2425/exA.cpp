#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string ls = s;

    for (int i = 0; i < s.size(); i++)
    {
        ls[i] = tolower(s[i]);
    }

    bool ascending = true;
    for (int i = 1; i < ls.size(); i++)
    {
        if (ls[i] < ls[i - 1])
        {
            ascending = false;
            break;
        }
    }

    bool descending = true;
    for (int i = 1; i < ls.size(); i++)
    {
        if (ls[i] > ls[i - 1])
        {
            descending = false;
            break;
        }
    }

    if (ascending || descending)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}