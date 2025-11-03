#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;
const int MAX_ST = MAX * 4;

struct Node {
    int pref, suff, best, len;
    Node() : pref(0), suff(0), best(0), len(0) {}
    Node(int p, int s, int b, int l) : pref(p), suff(s), best(b), len(l) {}
};

Node segmentTree[MAX_ST];
int A[MAX];
int n;

// função para verificar se o número contém 42
bool encontrei42(int x) {
    string s = to_string(x);
    return s.find("42") != string::npos;
}

Node merge(Node L, Node R) {
    if (L.len == 0) return R;
    if (R.len == 0) return L;
    
    Node res;
    res.len = L.len + R.len;
    res.pref = (L.pref == L.len) ? L.len + R.pref : L.pref;
    res.suff = (R.suff == R.len) ? R.len + L.suff : R.suff;
    res.best = max({L.best, R.best, L.suff + R.pref});
    return res;
}

// Build initial segtree from array A
void build(int pos, int start, int end) {
    if (start == end) {
        segmentTree[pos] = Node(A[start], A[start], A[start], 1);
    } else {
        int middle = (start + end) / 2;
        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);
        segmentTree[pos] = merge(segmentTree[pos * 2], segmentTree[pos * 2 + 1]);
    }
}

// Update node n to value v
void update(int pos, int start, int end, int n, int v) {
    if (start > n || end < n) return;
    if (start == end) {
        segmentTree[pos] = Node(v, v, v, 1);
    } else {
        int middle = (start + end) / 2;
        update(pos * 2, start, middle, n, v);
        update(pos * 2 + 1, middle + 1, end, n, v);
        segmentTree[pos] = merge(segmentTree[pos * 2], segmentTree[pos * 2 + 1]);
    }
}

// Make a query of interval [a,b]
Node query(int pos, int start, int end, int a, int b) {
    if (end < a || start > b) return Node(0, 0, 0, 0);
    if (a <= start && end <= b) return segmentTree[pos];
    
    int middle = (start + end) / 2;
    Node L = query(pos * 2, start, middle, a, b);
    Node R = query(pos * 2 + 1, middle + 1, end, a, b);
    return merge(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num_queries;
    cin >> n >> num_queries;
    
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (encontrei42(x)) {
            A[i] = 1;
        } else {
            A[i] = 0;
        }
    }
    
    build(1, 1, n);
    
    for (int i = 0; i < num_queries; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos, val;
            cin >> pos >> val;
            if (encontrei42(val)) {
                update(1, 1, n, pos, 1);
            } else {
                update(1, 1, n, pos, 0);
            }
        } else {
            int l, r;
            cin >> l >> r;
            Node res = query(1, 1, n, l, r);
            cout << res.best << "\n";
        }
    }
    
    return 0;
}
