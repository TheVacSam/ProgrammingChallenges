#include <bits/stdc++.h>
using namespace std;

void constructLps(string &pat, vector<int> &lps) {

    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    int i = 1;
    while (i < pat.length()) {

        // If characters match, increment the size of lps
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }

        // If there is a mismatch
        else {
            if (len != 0) {
                // Update len to the previous lps value
                // to avoid reduntant comparisons
                len = lps[len - 1];
            }
            else {
                // If no matching prefix found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    vector<int> lps(n);
    constructLps(s, lps);

    int len = lps[n - 1];

    if (len == 0) {
        cout << "Just a legend";
        return 0;
    }

    int midlps = 0;
    for (int i = 0; i < n - 1; i++) { 
        if (lps[i] > midlps)
            midlps = lps[i];
    }

    while (len > midlps) {
        len = lps[len - 1];
    }

    if (len > 0) {
        cout << s.substr(0, len);
    } else {
        cout << "Just a legend";
    }

    return 0;
}