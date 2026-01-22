#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;
    string word;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isEndOfWord = false;
        word = "";
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int idx = c - 'A';
            if (curr->children[idx] == nullptr)
            {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
        curr->word = word;
    }
};

int getScore(int len)
{
    if (len <= 2)
        return 0;
    if (len <= 4)
        return 1;
    if (len == 5)
        return 2;
    if (len == 6)
        return 3;
    if (len == 7)
        return 5;
    return 11;
}

void dfs(vector<string> &board, int i, int j, TrieNode *node,
         vector<vector<bool>> &visited, set<string> &foundWords)
{

    if (i < 0 || i >= 4 || j < 0 || j >= 4 || visited[i][j])
    {
        return;
    }

    char c = board[i][j];
    int idx = c - 'A';

    if (node->children[idx] == nullptr)
    {
        return;
    }

    node = node->children[idx];

    if (node->isEndOfWord)
    {
        foundWords.insert(node->word);
    }

    visited[i][j] = true;

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int d = 0; d < 8; d++)
    {
        dfs(board, i + dx[d], j + dy[d], node, visited, foundWords);
    }

    visited[i][j] = false;
}

int main()
{
    int n;
    cin >> n;

    for (int game = 1; game <= n; game++)
    {
        vector<string> board(4);

        for (int i = 0; i < 4; i++)
        {
            cin >> board[i];
        }

        int m;
        cin >> m;

        Trie trie;
        for (int i = 0; i < m; i++)
        {
            string word;
            cin >> word;
            trie.insert(word);
        }

        set<string> foundWords;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                vector<vector<bool>> visited(4, vector<bool>(4, false));
                dfs(board, i, j, trie.root, visited, foundWords);
            }
        }

        int totalScore = 0;
        for (const string &word : foundWords)
        {
            totalScore += getScore(word.length());
        }

        cout << "Score for Boggle game #" << game << ": " << totalScore << endl;
    }

    return 0;
}