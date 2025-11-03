#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> seq(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }

    map<int, int> freq;

    for (int x : seq)
    {
        freq[x]++;
    }

    int remove = 0;

    for (auto k : freq)
    {
        int val = k.first;
        int count = k.second;

        if (count >= val)
        {
            remove += count - val;
        }
        else
        {
            remove += count;
        }
    }

    cout << remove << endl;

    return 0;
}
//O(N)