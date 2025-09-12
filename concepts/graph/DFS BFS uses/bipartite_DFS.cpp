#include <bits/stdc++.h>
using namespace std;

enum Colors
{
    WHITE,
    GRAY,
    BLACK
};

// DFS for bipartite check
bool DFS(int vertex, vector<vector<int>> &graph, vector<int> &color, int currentColor)
{
    color[vertex] = currentColor;

    for (int neighbor : graph[vertex])
    {
        if (color[neighbor] == -1)
        {
            // Assign opposite color to neighbor
            if (!DFS(neighbor, graph, color, 1 - currentColor))
                return false;
        }
        else if (color[neighbor] == currentColor)
        {
            // Neighbor has same color → not bipartite
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);

    // Undirected graph example
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<int> color(n, -1); // -1 means uncolored

    bool isBipartite = true;

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!DFS(i, graph, color, 0))
            {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite)
        cout << "Graph is bipartite ✅\n";
    else
        cout << "Graph is NOT bipartite ❌\n";

    // Optional: print vertex colors
    cout << "Vertex colors:\n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << color[i] << "\n";
}
