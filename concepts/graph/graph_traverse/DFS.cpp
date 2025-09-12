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

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<Colors> color(n, WHITE);
    vector<int> parent(n, -1);
    vector<int> result;

    DFS(0, graph, color, parent, result);

    cout << "DFS Order:\n";
    for (int v : result)
        cout << v << " ";
    cout << "\nParents:\n";
    for (int i = 0; i < n; i++)
        cout << i << " -> " << parent[i] << "\n";
}
