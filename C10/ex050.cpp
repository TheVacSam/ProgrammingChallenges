#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &s)
{
    int n = s.length();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main()
{
    int n;
    int testCase = 1;

    while (cin >> n && n != 0)
    {
        string s;
        cin >> s;

        cout << "Test case #" << testCase << endl;

        vector<int> lps = computeLPS(s);

        for (int i = 2; i <= n; i++)
        {

            int len = lps[i - 1];

            int period = i - len;

            if (len > 0 && i % period == 0)
            {
                int k = i / period;

                if (k > 1)
                {
                    cout << i << " " << k << endl;
                }
            }
        }

        cout << endl;
        testCase++;
    }

    return 0;
}