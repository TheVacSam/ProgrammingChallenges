#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
int sizem;

int query(int pos)
{
    int sum = 0;
    while (pos > 0)
    {
        sum += tree[pos];
        pos -= (pos & -pos);
    }
    return sum;
}

void update(int pos)
{
    while (pos <= sizem)
    {
        tree[pos]++;
        pos += (pos & -pos);
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    sizem = m;
    tree.assign(m + 1, 0);

    vector<pair<int, int>> roads;
    for (int i = 0; i < k; i++)
    {
        int east, west;
        cin >> east >> west;
        roads.push_back({east, west});
    }

    sort(roads.begin(), roads.end());

    long long intersections = 0;

    vector<int> city;
    int lastEast = -1;

    for (int i = 0; i < k; i++)
    {
        int east = roads[i].first;
        int west = roads[i].second;

        if (east != lastEast && !city.empty())
        {
            for (int w : city)
            {
                update(w);
            }
            city.clear();
        }

        int totalSeen = query(m);
        int endingBefore = query(west);
        int seenAfter = totalSeen - endingBefore;

        intersections += seenAfter;

        city.push_back(west);
        lastEast = east;
    }

    cout << intersections << endl;

    return 0;
}