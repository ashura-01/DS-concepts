/*
    0
   / \
  1   2
   \ /
    3

  Edges
  0 — 1

  0 — 2

  1 — 3

  2 — 3

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX;

void undirectedGraph()
{
    unordered_map<int, vector<int>> graph = {
        {0, {1, 2}},
        {1, {0, 3}},
        {2, {0, 3}},
        {3, {1, 2}}};

    cout << "The adjacency list:" << endl;

    for (auto &elements : graph)
    {
        cout << elements.first << " -> ";
        for (auto &vectorElements : elements.second)
        {
            cout << vectorElements << ", ";
        }

        cout << endl;
    }
}

int32_t main()
{

    cout << "This is undirected graph" << endl;
    undirectedGraph();

    return 0;
}