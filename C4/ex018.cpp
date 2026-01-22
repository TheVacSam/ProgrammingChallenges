// Example solution for CSES: Dynamic Range Sum Queries
// Pedro Ribeiro (DCC/FCUP)
// O((n+q) log n) using segment trees (with arrays)

#include <bits/stdc++.h>

using namespace std;

// -----------------------------------------------------------------
// An example simple segment tree implementation with arrays
// -----------------------------------------------------------------

const int MAX = 200005; // Capacity of Segment Tree
const int MAX_ST = MAX * 4;

const int NEUTRAL = 0; // Neutral element

typedef int64_t st_value; // type of segment tree value

int n;               // Number of elements in the segtree
st_value v[MAX];     // Array of values
st_value st[MAX_ST]; // Segtree (in this case storing interval sums)

// Merge contents of nodes a and b
st_value merge(st_value a, st_value b)
{
    return a + b;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end)
{
    if (start == end)
    {
        st[pos] = v[start];
    }
    else
    {
        int middle = start + (end - start) / 2;
        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);
        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
}

// Update node n to value v
void update(int pos, int start, int end, int n, st_value v)
{
    if (start > n || end < n)
        return;
    if (start == end)
    {
        st[pos] = v;
    }
    else
    {
        int middle = start + (end - start) / 2;
        update(pos * 2, start, middle, n, v);
        update(pos * 2 + 1, middle + 1, end, n, v);
        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
}

// Make a query of interval [a,b]
st_value query(int pos, int start, int end, int a, int b)
{
    if (start > b || end < a)
        return NEUTRAL;
    if (start >= a && end <= b)
        return st[pos];

    int middle = start + (end - start) / 2;
    st_value l = query(pos * 2, start, middle, a, b);
    st_value r = query(pos * 2 + 1, middle + 1, end, a, b);
    return merge(l, r);
}

// ---------------------------------------------------------

struct Element
{
    int val, pos;

    bool operator<(const Element &other) const
    {
        return val > other.val; // descending
    }
};

struct Query
{
    int i, j, k, index;
    bool operator<(const Query &other) const
    {
        return k > other.k; // k descending
    }
};

int main()
{
    int q;
    cin >> n >> q;

    vector<Element> elements(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elements[i].val;
        elements[i].pos = i + 1;
    }

    vector<Query> queries(q);
    vector<int> res(q);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].i >> queries[i].j >> queries[i].k;
        queries[i].index = i;
    }

    // sort by decreasing value
    sort(elements.begin(), elements.end());

    // sort by decreasing k
    sort(queries.begin(), queries.end());

    // segment tree
    build(1, 1, n);

    int eidx = 0;

    for (int i = 0; i < q; i++)
    {
        while (eidx < n && elements[eidx].val > queries[i].k)
        {
            update(1, 1, n, elements[eidx].pos, 1);
            eidx++;
        }

        res[queries[i].index] = query(1, 1, n, queries[i].i, queries[i].j);
    }

    for (int i = 0; i < q; i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}
