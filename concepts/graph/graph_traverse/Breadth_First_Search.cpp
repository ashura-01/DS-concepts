#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void BFS(unordered_map<int, vector<int>> &adj, int vertex, vector<bool> &visited, vector<int> &result)
{
    queue<int> que;
    que.push(vertex);
    visited[vertex] = true; 
    result.push_back(vertex);

    while (!que.empty())
    {
        int current = que.front(); 
        que.pop();

        for (int &neighbor : adj[current])
        {
            if (!visited[neighbor])
            {
                que.push(neighbor);
                visited[neighbor] = true;
                result.push_back(neighbor);
            }
        }
    }
}

vector<int> makingGraphFromInput(vector<vector<int>> graph)
{
    unordered_map<int, vector<int>> adjlist;

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j : graph[i])
        {
            adjlist[i].push_back(j);
        }
    }

    vector<int> result;
    vector<bool> visited(graph.size(), false);
    BFS(adjlist, 0, visited, result);

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

    cout << edges.size() << endl;

    vector<int> bfs_result = makingGraphFromInput(edges); 

    cout << "BFS Traversal from vertex 0: "; 
    for (int node : bfs_result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
