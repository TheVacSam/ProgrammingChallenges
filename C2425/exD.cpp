#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int cost = 0;
    bool shiftPressed = false;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c == ' ')
        {
            // Espaço sempre custa 1 cent
            cost++;
            shiftPressed = false;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            // Letra maiúscula
            if (!shiftPressed)
            {
                // Precisa pressionar Shift
                cost++;
                shiftPressed = true;
            }
            // Verifica se é diferente do caractere anterior
            if (i == 0 || s[i - 1] != c)
            {
                cost++;
            }
        }
        else
        {
            // Letra minúscula
            if (shiftPressed)
            {
                // Precisa soltar Shift
                shiftPressed = false;
            }
            // Verifica se é diferente do caractere anterior
            if (i == 0 || s[i - 1] != c)
            {
                cost++;
            }
        }
    }

    cout << cost << endl;

    return 0;
}
