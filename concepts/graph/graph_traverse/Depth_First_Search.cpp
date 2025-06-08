// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

// DFS is a recurtion based holly shit
void DFS(unordered_map<int, vector<int>> &adj, int vertex, vector<bool> &visited, vector<int> &result)
{
    if (visited[vertex])
    {
        return;
    }

    visited[vertex] = true;

    result.push_back(vertex);

    for (int &neighbor : adj[vertex])
    {
        if (!visited[neighbor])
        {
            DFS(adj, neighbor, visited, result);
        }
    }
}

vector<int> makingGraphFromInput( vector<vector<int>> &graph)
{
    int vertices = graph.size();
    unordered_map<int, vector<int>> adjlist;

    // Build adjacency list from given input
    for (int i = 0; i < vertices; i++)
    {
        for (int j : graph[i])
        {
            adjlist[i].push_back(j);
        }
    }

    vector<int> result;
    vector<bool> visited(vertices, false);

    DFS(adjlist, 0, visited, result);

    return result;
}

int32_t main()
{

    int V = 5;

    vector<vector<int>> edges = {
        {2, 3, 1}, // Neighbors of 0
        {0},       // Neighbors of 1
        {0, 4},    // Neighbors of 2
        {0},       // Neighbors of 3
        {2}        // Neighbors of 4
    };

    cout<<edges.size()<<endl;

    vector<int> dfs_result = makingGraphFromInput(edges);

    cout << "DFS Traversal from vertex 0: ";
    for (int node : dfs_result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}