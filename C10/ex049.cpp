#include <bits/stdc++.h>
using namespace std;

struct Suffix
{
    int index;
    string suff;
};

bool cmp(const Suffix &a, const Suffix &b)
{
    return a.suff < b.suff;
}

vector<int> buildSuffixArray(const string &text)
{
    int n = text.length();
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = text.substr(i);
    }

    sort(suffixes.begin(), suffixes.end(), cmp);

    vector<int> suffixArr(n);
    for (int i = 0; i < n; i++)
    {
        suffixArr[i] = suffixes[i].index;
    }

    return suffixArr;
}

vector<int> buildLCPArray(const string &text, const vector<int> &suffixArr)
{
    int n = text.length();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n);

    for (int i = 0; i < n; i++)
    {
        invSuff[suffixArr[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (invSuff[i] == n - 1)
        {
            k = 0;
            continue;
        }

        int j = suffixArr[invSuff[i] + 1];

        while (i + k < n && j + k < n && text[i + k] == text[j + k])
        {
            k++;
        }

        lcp[invSuff[i]] = k;

        if (k > 0)
            k--;
    }

    return lcp;
}

int getSequenceId(int pos, const vector<int> &boundaries)
{
    for (int i = 0; i < boundaries.size(); i++)
    {
        if (pos < boundaries[i])
            return i;
    }
    return boundaries.size() - 1;
}

bool appearsInMoreThanHalf(const vector<int> &suffixArr, const vector<int> &lcp,
                           int start, int end, int len,
                           const vector<int> &boundaries, int n)
{
    set<int> sequences;

    for (int i = start; i <= end; i++)
    {
        int seqId = getSequenceId(suffixArr[i], boundaries);
        sequences.insert(seqId);
    }

    return sequences.size() > n / 2;
}

int main()
{
    int n;
    bool firstCase = true;

    while (cin >> n && n != 0)
    {
        if (!firstCase)
        {
            cout << endl;
        }
        firstCase = false;

        vector<string> sequences(n);
        for (int i = 0; i < n; i++)
        {
            cin >> sequences[i];
        }

        string combined;
        vector<int> boundaries;

        for (int i = 0; i < n; i++)
        {
            combined += sequences[i];
            combined += char('z' + 1 + i);
            boundaries.push_back(combined.length());
        }

        vector<int> suffixArr = buildSuffixArray(combined);
        vector<int> lcp = buildLCPArray(combined, suffixArr);

        int maxLen = 0;
        set<string> results;

        int m = combined.length();

        for (int len = m - 1; len >= 1; len--)
        {
            if (len < maxLen)
                break;

            for (int i = 0; i < m - 1; i++)
            {
                if (lcp[i] >= len)
                {
                    int start = i;
                    int minLCP = lcp[i];

                    while (i < m - 1 && lcp[i] >= len)
                    {
                        minLCP = min(minLCP, lcp[i]);
                        i++;
                    }

                    int end = i;

                    if (appearsInMoreThanHalf(suffixArr, lcp, start, end, minLCP, boundaries, n))
                    {
                        string substr = combined.substr(suffixArr[start], minLCP);

                        bool valid = true;
                        for (char c : substr)
                        {
                            if (c > 'z')
                            {
                                valid = false;
                                break;
                            }
                        }

                        if (valid && minLCP > maxLen)
                        {
                            maxLen = minLCP;
                            results.clear();
                            results.insert(substr);
                        }
                        else if (valid && minLCP == maxLen)
                        {
                            results.insert(substr);
                        }
                    }
                }
            }
        }

        if (maxLen == 0)
        {
            cout << "?" << endl;
        }
        else
        {
            for (const string &s : results)
            {
                cout << s << endl;
            }
        }
    }

    return 0;
}