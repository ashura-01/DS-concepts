#include <bits/stdc++.h>
using namespace std;

enum Colors
{
    WHITE,
    GRAY,
    BLACK
};

void DFS(int vertex, vector<vector<int>> &graph, vector<Colors> &color, vector<int> &parent, vector<int> &result)
{
    color[vertex] = GRAY;
    result.push_back(vertex);

    for (int neighbor : graph[vertex])
    {
        if (color[neighbor] == WHITE)
        {
            parent[neighbor] = vertex;
            DFS(neighbor, graph, color, parent, result);
        }
    }

    color[vertex] = BLACK;
}

void takeInput(vector<vector<int>> &graph, int &n, int &m, int &source)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cin >> source;
}

void printGraph(const vector<vector<int>> &graph, int n)
{
    cout << "Graph (Adjacency List):" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (int v : graph[i])
            cout << v << " ";
        cout << endl;
    }
}

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    takeInput(graph, n, m, source);
    printGraph(graph, n);

    vector<Colors> color(n + 1, WHITE);
    vector<int> parent(n + 1, -1);
    vector<int> result;

    DFS(source, graph, color, parent, result);

    cout << "DFS Traversal:" << endl;
    for (int v : result)
        cout << v << " ";
    cout << endl;
}
