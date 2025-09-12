#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

bool dfsCycle(vector<int> adj[], int vertex, vector<bool> &visited, int parent)
{
    visited[vertex] = true;

    for (auto &node : adj[vertex])
    {
        if (node == parent)
            continue;

        if (visited[node])
            return true;

        if (dfsCycle(adj, node, visited, vertex))
            return true;
    }
    return false;
}

bool solveProblem(int numberOfVertex, vector<int> adj[])
{
    vector<bool> visited(numberOfVertex, false);

    for (int i = 0; i < numberOfVertex; i++)
    {
        if (!visited[i] && dfsCycle(adj, i, visited, -1))
        {
            return true;
        }
    }
    return false;
}

int32_t main()
{
    // Sample graph:
    // 5 vertices, 5 edges
    // 0-1-2-3-4 and back edge 4-1 forms a cycle

    int n = 5; // number of vertices
    vector<int> adj[n];

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}};

    for (auto &[u, v] : edges)
    {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (solveProblem(n, adj))
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }

    return 0;
}
