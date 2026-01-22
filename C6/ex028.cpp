#include <bits/stdc++.h>
using namespace std;

vector<int> lonis(const vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return {};
    }

    vector<int> lengths(n);

    vector<int> tails;

    for (int i = 0; i < n; ++i)
    {
        int x = nums[i];

        int ind = lower_bound(tails.begin(), tails.end(), x) - tails.begin();

        if (ind == tails.size())
        {
            tails.push_back(x);
        }
        else
        {
            tails[ind] = x;
        }

        lengths[i] = ind + 1;
    }

    return lengths;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    if (cin >> t)
    {

        while (t--)
        {
            int n;
            cin >> n;

            vector<int> s(n);

            for (int i = 0; i < n; i++)
            {
                cin >> s[i];
            }

            vector<int> lis = lonis(s);

            vector<int> reversed = s;
            reverse(reversed.begin(), reversed.end());

            vector<int> lds = lonis(reversed);
            reverse(lds.begin(), lds.end());

            int max_wavio = 0;
            for (int i = 0; i < n; i++)
            {
                int current_len = 2 * min(lis[i], lds[i]) - 1;
                if (current_len > max_wavio)
                {
                    max_wavio = current_len;
                }
            }

            cout << max_wavio << endl;
        }
    }
    return 0;
}
