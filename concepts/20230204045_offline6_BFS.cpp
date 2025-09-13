#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int source, vector<vector<int>> &graph, int n)
{
    vector<int> level(n, -1);
    vector<int> result;
    queue<int> q;

    level[source] = 0;
    q.push(source);
    result.push_back(source);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int v : graph[x])
        {
            if (level[v] == -1)
            {
                level[v] = level[x] + 1;
                q.push(v);
                result.push_back(v);
            }
        }
    }

    return result;
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
    for (int i = 0; i <= n; i++)
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

    vector<int> result = BFS(source, graph, n + 1);

    cout << "BFS Traversal:" << endl;
    for (int v : result)
        cout << v << " ";
    cout << endl;
}
