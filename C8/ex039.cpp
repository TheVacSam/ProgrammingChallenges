#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
set<char> letters;

void dfs(int v)
{
    visited[v] = true;
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    ans.push_back(v);
}

void topological_sort(int n)
{
    visited.assign(n, false);
    ans.clear();

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}

int main()
{
    int n;
    cin >> n;

    vector<string> words;

    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        words.push_back(word);

        for(char c : word){
            letters.insert(c);
        }
    }

    adj.assign(26, vector<int>());

    for(int i=0; i<n-1; i++){
        string w1 = words[i];
        string w2 = words[i+1];

        int k= min(w1.size(), w2.size());
        
        for(int j=0; j<k; j++){
            if(w1[j] != w2[j]){
                int from = w1[j] - 'A';
                int to = w2[j] - 'A';
                
                adj[from].push_back(to);
                break;
            }
        }
    }

    topological_sort(26);


    for(int idx : ans){
        char c = 'A' + idx;

        if(letters.count(c)){
            cout << c;
        }
    }
    cout << endl;
    return 0;
}