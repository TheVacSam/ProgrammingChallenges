/*[PC002] Increasing Array

You are given an array of

integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element. On each move, you may increase the value of any element by one. What is the minimum number of moves required?
Input

The first input line contains an integer

: the size of the array.

Then, the second line contains
integers

: the contents of the array.
Output

Print a line with one integer: the minimum number of moves.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n; // ler o n

    vector<int> array(n); // gerar o array

    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; // add numeros ao array
    }

    long moves = 0;

    for (int i = 1; i < n; i++)
    {
        if (array[i] < array[i - 1]) // verificar se o elemento atual é menor que o anterior
        {
            moves += array[i - 1] - array[i]; // calculo da diferença
            array[i] = array[i - 1];          // alterrar o valor atual, para o valor anterior, caso o anterior seja maior
        }
    }

    cout << moves << endl;
    return 0;
}
