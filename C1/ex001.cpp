/*[PC001] Repetitions

You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.
Input

The only input line contains a string of characters.
Output

Print a line with one integer: the length of the longest repetition
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string seq;
    cin >> seq;

    int max = 1;
    int count = 1;

    for (int i = 1; i < seq.size(); i++)
    {
        if (seq[i] == seq[i - 1])
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
        else
        {
            count = 1;
        }
    }
    cout << max << endl;

    return 0;
}
