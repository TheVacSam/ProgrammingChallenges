#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    vector<long long> freq(n + 1, 0);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        freq[l]++;
        freq[r + 1]--;
    }

    for (int i = 1; i < n; i++)
    {
        freq[i] += freq[i - 1];
    }

    freq.pop_back();

    sort(values.begin(), values.end());
    sort(freq.begin(), freq.end());

    long long maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum += values[i] * freq[i];
    }

    cout << maxSum << endl;

    return 0;
}