#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int source, vector<vector<int>> &graph, int n)
{
    vector<int> level(n, -1); // initialize all levels as -1
    vector<int> result;       // BFS traversal order
    queue<int> q;

    level[source] = 0; // level of source
    q.push(source);
    result.push_back(source);

    while (!q.empty())
    {
        int x = q.front();
        q.pop(); // remove from queue

        for (int v : graph[x])
        { // all adjacent nodes
            if (level[v] == -1)
            { // not visited
                level[v] = level[x] + 1;
                q.push(v);
                result.push_back(v);
            }
        }
    }

    return result; // return BFS traversal
}

int main()
{
    int n = 6;
    vector<vector<int>> graph(n);

    // Example graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    int source = 0;
    vector<int> result = BFS(source, graph, n);

    cout << "BFS Traversal:\n";
    for (int v : result)
        cout << v << " ";
    cout << "\n";
}
