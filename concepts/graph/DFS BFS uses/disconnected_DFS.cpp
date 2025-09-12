#include <bits/stdc++.h>
using namespace std;

void DFS(int vertex, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[vertex] = true;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);

    // Example directed graph
    graph[0] = {1, 2};
    graph[1] = {3};
    graph[2] = {};
    graph[3] = {};
    graph[4] = {5};
    graph[5] = {}; // note: disconnected component 4->5

    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, graph, visited);
            components++;
        }
    }

    cout << "Number of connected components (DFS reachable sets): " << components << "\n";

    if (components > 1)
        cout << "The graph is disconnected ❌\n";
    else
        cout << "The graph is connected ✅\n";
}
