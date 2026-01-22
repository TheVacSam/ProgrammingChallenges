#include <iostream>
#include <cstring>

using namespace std;

long long memo[51][51][2][51];

int Pairs;
int K;

long long solve(int a, int b, int last, int count)
{
    if (count > K)
        return 0;

    if (a == Pairs && b == Pairs)
        return 1;

    if (memo[a][b][last][count] != -1)
        return memo[a][b][last][count];

    long long result = 0;

    if (a < Pairs)
    {
        if (last == 0)
        {
            result += solve(a + 1, b, 0, count + 1);
        }
        else
        {
            result += solve(a + 1, b, 0, 1);
        }
    }

    if (b < a)
    {
        if (last == 1)
        {
            result += solve(a, b + 1, 1, count + 1);
        }
        else
        {
            result += solve(a, b + 1, 1, 1);
        }
    }

    memo[a][b][last][count] = result;

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
 
    while (T--)
    {
        int N;
        cin >> N >> K;

        if (N % 2 != 0)
        {
            cout << 0 << '\n';
            continue;
        }

        Pairs = N / 2;

        memset(memo, -1, sizeof(memo));

        cout << solve(1, 0, 0, 1) << '\n';
    }

    return 0;
}