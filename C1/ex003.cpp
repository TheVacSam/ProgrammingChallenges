/*
Forty-Two Password Inc. has created a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. You must help them validate their method by creating a program that checks if the original message is really encoded in the final string.
The Problem

Given two strings
and , you have to check if is a subsequence of , that is, if you can remove characters from such that the concatenation of the remaining characters is

.
Input

The first line contains
, the number of test cases that you will need to process. Each of the following lines contains and

, two strings of lowercase letters.
Output

For each test case (in the same order as they appear in the input) output a line with "yes" if
is a subsequence of and "no" otherwise.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        int j = 0, k = 0;

        while (j < a.size() && k < b.size())
        {
            if (a[j] == b[k])
            {
                j++;
            }
            k++;
        }

        if (j == a.size())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}