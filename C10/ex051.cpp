#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000003;
const int MAXN = 1005;

struct AhoCorasick
{
    struct Node
    {
        map<char, int> children;
        int fail;
        bool isEnd;

        Node() : fail(0), isEnd(false) {}
    };

    vector<Node> nodes;
    int nodeCount;

    AhoCorasick()
    {
        nodes.resize(MAXN);
        nodeCount = 1;
    }

    char normalize(char c)
    {
        if (c == '0')
            return 'o';
        if (c == '1')
            return 'i';
        if (c == '3')
            return 'e';
        if (c == '5')
            return 's';
        if (c == '7')
            return 't';
        if (c >= 'A' && c <= 'Z')
            return c - 'A' + 'a';
        return c;
    }

    void insert(const string &word)
    {
        int curr = 0;
        for (char c : word)
        {
            char nc = normalize(c);
            if (nodes[curr].children.find(nc) == nodes[curr].children.end())
            {
                nodes[curr].children[nc] = nodeCount++;
            }
            curr = nodes[curr].children[nc];
        }
        nodes[curr].isEnd = true;
    }

    void buildFailureLinks()
    {
        queue<int> q;

        // Estados de profundidade 1 têm fail link para raiz
        for (auto &p : nodes[0].children)
        {
            int child = p.second;
            nodes[child].fail = 0;
            q.push(child);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (nodes[nodes[curr].fail].isEnd)
            {
                nodes[curr].isEnd = true;
            }

            for (auto &p : nodes[curr].children)
            {
                char c = p.first;
                int child = p.second;
                q.push(child);

                int fail = nodes[curr].fail;
                while (fail != 0 && nodes[fail].children.find(c) == nodes[fail].children.end())
                {
                    fail = nodes[fail].fail;
                }

                if (nodes[fail].children.find(c) != nodes[fail].children.end() &&
                    nodes[fail].children[c] != child)
                {
                    nodes[child].fail = nodes[fail].children[c];
                }
                else
                {
                    nodes[child].fail = 0;
                }

                if (nodes[nodes[child].fail].isEnd)
                {
                    nodes[child].isEnd = true;
                }
            }
        }
    }

    int transition(int state, char c)
    {
        char nc = normalize(c);

        while (state != 0 && nodes[state].children.find(nc) == nodes[state].children.end())
        {
            state = nodes[state].fail;
        }

        if (nodes[state].children.find(nc) != nodes[state].children.end())
        {
            return nodes[state].children[nc];
        }
        return 0;
    }

    bool isSafe(int state)
    {
        return !nodes[state].isEnd;
    }
};

int main()
{
    int A, B, N;
    cin >> A >> B >> N;

    AhoCorasick ac;

    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;
        ac.insert(word);
    }

    ac.buildFailureLinks();

    long long dp[21][MAXN][2][2][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0][0] = 1;

    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (int pos = 0; pos < B; pos++)
    {
        for (int state = 0; state < ac.nodeCount; state++)
        {
            for (int hasLower = 0; hasLower <= 1; hasLower++)
            {
                for (int hasUpper = 0; hasUpper <= 1; hasUpper++)
                {
                    for (int hasDigit = 0; hasDigit <= 1; hasDigit++)
                    {
                        if (dp[pos][state][hasLower][hasUpper][hasDigit] == 0)
                            continue;

                        long long ways = dp[pos][state][hasLower][hasUpper][hasDigit];

                        for (char c : chars)
                        {
                            int newState = ac.transition(state, c);

                            if (!ac.isSafe(newState))
                                continue;

                            int newLower = hasLower || (c >= 'a' && c <= 'z');
                            int newUpper = hasUpper || (c >= 'A' && c <= 'Z');
                            int newDigit = hasDigit || (c >= '0' && c <= '9');

                            dp[pos + 1][newState][newLower][newUpper][newDigit] =
                                (dp[pos + 1][newState][newLower][newUpper][newDigit] + ways) % MOD;
                        }
                    }
                }
            }
        }
    }

    long long result = 0;
    for (int pos = A; pos <= B; pos++)
    {
        for (int state = 0; state < ac.nodeCount; state++)
        {
            result = (result + dp[pos][state][1][1][1]) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}