#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

int m, result = 0;

void DFS(unordered_map<int, vector<int>> &adj, int vertex, vector<bool> &visited, vector<int> &arr, int consec_cats, int parent) {
    visited[vertex] = true;

   
    if (arr[vertex - 1] == 1)
        consec_cats++;
    else
        consec_cats = 0;

   
    if (consec_cats > m)
        return;

    bool isLeaf = true;
    for (int neighbor : adj[vertex]) {
        if (!visited[neighbor]) {
            isLeaf = false;
            DFS(adj, neighbor, visited, arr, consec_cats, vertex);
        }
    }

   
    if (isLeaf)
        result++;
}

void solveProblem() {
    int n;
    cin >> n >> m;

    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    unordered_map<int, vector<int>> adjList;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);  
    }

    vector<bool> visited(n + 1, false);
    DFS(adjList, 1, visited, arr, 0, -1);

    cout << result << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solveProblem();
    }

    return 0;
}
