#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj, int start, int n, bool returnLevel = false) {
    vector<bool> visited(n, false);
    vector<int> result;       // BFS order
    vector<int> level(n, -1); // levels initialized as -1

    queue<int> que;
    que.push(start);
    visited[start] = true;
    result.push_back(start);
    level[start] = 0;

    while (!que.empty()) {
        int current = que.front();
        que.pop();

        for (int neighbor : adj[current]) { // iterate over neighbors
            if (!visited[neighbor]) {
                que.push(neighbor);
                visited[neighbor] = true;
                result.push_back(neighbor);
                level[neighbor] = level[current] + 1;
            }
        }
    }

    return returnLevel ? level : result; // return either levels or BFS order
}

int main() {
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // Example undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    // Get BFS order
    vector<int> bfsOrder = BFS(adj, 0, n, false);
    cout << "BFS Order: ";
    for (int v : bfsOrder) cout << v << " ";
    cout << "\n";

    // Get levels
    vector<int> levels = BFS(adj, 0, n, true);
    cout << "Node : Level\n";
    for (int i = 0; i < n; i++) cout << i << " : " << levels[i] << "\n";

    return 0;
}
