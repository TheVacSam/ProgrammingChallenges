/*
 */

#include <bits/stdc++.h>
using namespace std;

bool fit(vector<double> pies, int friends, double v)
{
    int count = 0;
    for (double i : pies)
    {
        count += (int)(i / v);
    }
    return count >= friends;
}

double maxVol(vector<int> &r, int friends)
{
    vector<double> pies(r.size());
    double lims = 0;

    for (int i = 0; i < r.size(); i++)
    {
        pies[i] = M_PI * r[i] * r[i];
        lims = max(lims, pies[i]);
    }

    double limi = 0;

    while (lims - limi > 1e-6)
    {
        double mid = (limi + lims) / 2;
        if (fit(pies, friends, mid))
        {
            limi = mid;
        }
        else
        {
            lims = mid;
        }
    }

    return limi;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, f;
        cin >> n >> f;

        vector<int> r(n); // raio

        for (int i = 0; i < n; i++)
        {
            cin >> r[i];
        }

        int pessoas = f + 1;
        double aux = maxVol(r, pessoas);
        printf("%.4f\n", aux);
    }

    return 0;
}