#include <bits/stdc++.h>
using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

void DFS(int u, vector<vector<int>> &adj, vector<Color> &color, vector<int> &parent, vector<int> &result)
{
    color[u] = GRAY;
    result.push_back(u);

    for (int v : adj[u])
    {
        if (color[v] == WHITE)
        {
            parent[v] = u;
            DFS(v, adj, color, parent, result);
        }
    }

    color[u] = BLACK;
}

int main()
{
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    vector<Color> color(n, WHITE);
    vector<int> parent(n, -1);
    vector<int> result;

    DFS(0, adj, color, parent, result);

    cout << "DFS Order:\n";
    for (int v : result)
        cout << v << " ";
    cout << "\nParents:\n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << parent[i] << "\n";
}
