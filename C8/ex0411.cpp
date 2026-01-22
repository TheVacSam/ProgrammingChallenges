#include <bits/stdc++.h>
using namespace std;

vector<int> A(vector<int> s)
{

    reverse(s.begin(), s.end());
    return s;
}

vector<int> B(vector<int> s)
{
    // fazer o circular shift

    vector<int> ss = s;
    ss[0] = s[3];
    ss[1] = s[0];
    ss[2] = s[1];
    ss[3] = s[2];

    ss[4] = s[5];
    ss[5] = s[6];
    ss[6] = s[7];
    ss[7] = s[4];

    return ss;
}

vector<int> C(vector<int> s)
{
    vector<int> ss = s;
    ss[1] = s[6];
    ss[2] = s[1];
    ss[6] = s[5];
    ss[5] = s[2];

    return ss;
}

int main()
{

    vector<int> start = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int> target(8);

    for (int i = 0; i < 8; i++)
    {
        cin >> target[i];
    }

    if (start == target)
    {
        cout << 0 << endl;
        cout << endl;
        return 0;
    }

    // BFS
    // Queue armazena pares: {configuração_atual, sequência_de_movimentos}
    queue<pair<vector<int>, string>> q;
    q.push({start, ""});

    // Set para visitados
    set<vector<int>> visited;
    visited.insert(start);

    while (!q.empty())
    {
        pair<vector<int>, string> curr = q.front();
        q.pop();

        vector<int> s = curr.first;
        string path = curr.second;

        vector<int> cA = A(s);

        if (cA == target)
        {
            cout << path.length() + 1 << endl;
            cout << path + "A" << endl;
            return 0;
        }

        if (visited.find(cA) == visited.end())
        {
            visited.insert(cA);
            q.push({cA, path + "A"});
        }

        vector<int> cB = B(s);
        if (cB == target)
        {
            cout << path.length() + 1 << endl;
            cout << path + "B" << endl;
            return 0;
        }
        if (visited.find(cB) == visited.end())
        {
            visited.insert(cB);
            q.push({cB, path + "B"});
        }

        vector<int> cC = C(s);
        if (cC == target)
        {
            cout << path.length() + 1 << endl;
            cout << path + "C" << endl;
            return 0;
        }
        if (visited.find(cC) == visited.end())
        {
            visited.insert(cC);
            q.push({cC, path + "C"});
        }
    }

    return 0;
}