/*
Your task is to calculate the number of trailing zeros in the factorial

.

For example,

and it has 4 trailing zeros.
Input

The only input line has an integer

.
Output

Print a line with one integer: the number of trailing zeros in n!.
.*/

// calcular os 0's atraves da divisao por 10 mb nao funciona de todo
// input n
// fazer o fatorial, mb not
// dura praxis sed praxis
// virtus unita fortius agit

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;

    for (int i = 5; i <= n; i *= 5)
    {
        count += n / i;
    }
    cout << count << endl;
    return 0;
}