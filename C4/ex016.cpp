// Example solution for CSES: Dynamic Range Sum Queries
// Pedro Ribeiro (DCC/FCUP)
// O((n+q) log n) using segment trees (with arrays)

#include <bits/stdc++.h>

using namespace std;

const int MAX = 200005; // Capacidade
const int MAX_ST = MAX * 4;

struct Node
{
    int lval, rval;     // Valor no inicial e final do intervalo
    int lcount, rcount; // Count de quantas vezes aparece
    int freq;           // Frequencia maxima para determinado intervalo
    int size;           // Tamanho do intervalo (final - inicial + 1)
};

// O elemento NEUTRAL tem tamanho 0 para ser "ignorado" no merge
const Node NEUTRAL = {0, 0, 0, 0, 0, 0};

typedef Node st_value; // tipo do valor da segment tree

int n;               // Número de elementos
int a[MAX];          // Array de valores de input
st_value st[MAX_ST]; // A própria Segment Tree

// Combina os nós filhos 'left' e 'right'
st_value merge(st_value left, st_value right)
{
    // Se um deles for neutro, retorna o outro
    if (left.size == 0)
        return right;

    if (right.size == 0)
        return left;

    st_value res;
    res.size = left.size + right.size;

    // A frequencia é no minimo, o maximo das respostas dos filhos
    res.freq = max(left.freq, right.freq);

    // Verifica se ha um novo bloco na fronteira
    if (left.rval == right.lval)
    {
        res.freq = max(res.freq, left.rcount + right.lcount);
    }

    // Novo prefixo (lval, lcount)
    res.lval = left.lval;
    if (left.lval == right.lval && left.lcount == left.size)
    {
        res.lcount = left.lcount + right.lcount;
    }
    else
    {
        res.lcount = left.lcount;
    }

    // Agora é calculado o novo sufixo (rval, rcount)
    res.rval = right.rval;
    if (right.rval == left.rval && right.rcount == right.size)
    {
        res.rcount = left.rcount + right.rcount;
    }
    else
    {
        res.rcount = right.rcount;
    }

    // Retorna o nó final acabado de construir
    return res;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end)
{
    if (start == end)
    {
        // Representar o nó folha
        st[pos] = {a[start], a[start], 1, 1, 1, 1}; // lval, rval, lcount, rcount, freq, size
    }
    else
    {
        int middle = start + (end - start) / 2;
        build(pos * 2, start, middle);
        build(pos * 2 + 1, middle + 1, end);
        st[pos] = merge(st[pos * 2], st[pos * 2 + 1]);
    }
}

// Update node n to value v (nao uso)
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

int main()
{
    int q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= q; i++)
    {
        int j, k; // Valores da query
        cin >> j >> k;

        st_value result = query(1, 1, n, j, k);
        cout << result.freq << endl;
    }

    return 0;
}