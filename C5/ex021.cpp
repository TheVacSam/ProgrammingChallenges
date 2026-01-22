#include <bits/stdc++.h>
using namespace std;

// Encontra o max sum atraves do algoritmo de Kadane
//  Para cada posição do array, vai escolher entre manter o subarray ou começar de inicio
int maxSubarraySum(vector<int> &arr)
{
    int res = arr[0];
    int currSum = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        currSum = max(arr[i], currSum + arr[i]);
        res = max(res, currSum);
    }
    return res;
}

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> matriz(n, vector<int>(n));

    // lê a matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
    }

    // Constroi a matriz de cumulative sum
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = matriz[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int maxSum = INT_MIN;

    // faz a verificaçao de todos os pares possiveis
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> temp(n);

            for (int col = 0; col < n; col++)
            {
                temp[col] = sum[j + 1][col + 1] - sum[i][col + 1] - sum[j + 1][col] + sum[i][col];
            }
            maxSum = max(maxSum, maxSubarraySum(temp));
        }
    }

    cout << maxSum << endl;
    return 0;
}

// Complexidade O(n³)