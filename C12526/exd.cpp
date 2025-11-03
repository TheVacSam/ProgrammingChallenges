// Example solution for CSES: Dynamic Range Sum Queries
// Pedro Ribeiro (DCC/FCUP)
// O((n+q) log n) using segment trees (with explicit trees & pointers)

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int maxStreak;    // Maximum consecutive streak in this interval
  int leftStreak;   // Streak starting from the left
  int rightStreak;  // Streak ending at the right
  bool leftHas42;   // Does leftmost element contain 42?
  bool rightHas42;  // Does rightmost element contain 42?
  
  Node() : maxStreak(0), leftStreak(0), rightStreak(0), 
           leftHas42(false), rightHas42(false) {}
  
  Node(int val) {
    bool has42 = contains42(val);
    maxStreak = has42 ? 1 : 0;
    leftStreak = has42 ? 1 : 0;
    rightStreak = has42 ? 1 : 0;
    leftHas42 = has42;
    rightHas42 = has42;
  }
  
  static bool contains42(int num) {
    string s = to_string(num);
    return s.find("42") != string::npos;
  }
};

// -----------------------------------------------------------------
// An example simple segment tree class (with no garbage collection)
// -----------------------------------------------------------------

template <class T>
class SegTree
{

private:
    typedef struct node
    {
        struct node *left, *right;
        int start, end;
        T value;
    } *NodePr;

    NodePr root;
    function<T(T, T)> merge;
    T neutral;

    // Build initial segtree from vector v
    NodePr build(int start, int end, vector<T> &v)
    {
        NodePr cur = new struct NodePr;
        cur->start = start;
        cur->end = end;
        if (start == end)
        {
            cur->value = v[start - 1];
            cur->left = cur->right = nullptr;
        }
        else
        {
            int middle = start + (end - start) / 2;
            cur->left = build(start, middle, v);
            cur->right = build(middle + 1, end, v);
            cur->value = merge(cur->left->value, cur->right->value);
        }
        return cur;
    }

    // Update NodePr n to value v
    void update(NodePr cur, int n, T v)
    {
        if (cur->start > n || cur->end < n)
            return;
        if (cur->start == cur->end)
        {
            cur->value = v;
        }
        else
        {
            update(cur->left, n, v);
            update(cur->right, n, v);
            cur->value = merge(cur->left->value, cur->right->value);
        }
    }

    // Make a query of interval [a,b]
    T query(NodePr cur, int a, int b)
    {
        if (cur->start > b || cur->end < a)
            return neutral;
        if (cur->start >= a && cur->end <= b)
            return cur->value;

        T l = query(cur->left, a, b);
        T r = query(cur->right, a, b);
        return merge(l, r);
    }

public:
    SegTree(vector<T> &v, function<T(T, T)> m, T n)
    {
        neutral = n;
        merge = m;
        root = build(1, v.size(), v);
    }

    T query(int x, int y)
    {
        return query(root, x, y);
    }

    void update(int x, T r)
    {
        update(root, x, r);
    }
};

// ----------------------------------------------------

int main()
{

    int n, q;
    cin >> n >> q;
    vector<int64_t> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    auto merge = [](int64_t a, int64_t b)
    {
        return a + b;
    };
    SegTree<int64_t> st(v, merge, 0);

    for (int i = 1; i <= q; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
            st.update(a, b);
        else
            cout << st.query(a, b) << endl;
    }

    return 0;
}
