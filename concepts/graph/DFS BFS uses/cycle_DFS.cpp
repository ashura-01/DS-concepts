#include <bits/stdc++.h>
using namespace std;

enum Colors
{
    WHITE,
    GRAY,
    BLACK
};

bool DFS(int vertex, vector<vector<int>> &graph, vector<Colors> &color, vector<int> &result)
{
    color[vertex] = GRAY;
    result.push_back(vertex);

    for (int neighbor : graph[vertex])
    {
        if (color[neighbor] == WHITE)
        {
            if (DFS(neighbor, graph, color, result))
            {
                return true; 
            }
        }
        else if (color[neighbor] == GRAY)
        {
            
            return true;
        }
    }

    color[vertex] = BLACK;
    return false; 
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);

    // Example directed graph
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {4};
    graph[3] = {5};
    graph[4] = {5};
    graph[5] = {}; // no outgoing edges

    vector<Colors> color(n, WHITE);
    vector<int> result; // store DFS traversal order
    bool hasCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (color[i] == WHITE)
        {
            if (DFS(i, graph, color, result))
            {
                hasCycle = true;
                break;
            }
        }
    }

    cout << "DFS Order:\n";
    for (int v : result)
        cout << v << " ";
    cout << "\n";

    if (hasCycle)
        cout << "Directed graph contains a cycle ✅\n";
    else
        cout << "Directed graph does NOT contain a cycle ❌\n";
}
