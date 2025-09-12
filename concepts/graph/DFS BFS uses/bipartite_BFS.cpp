#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph, int n)
{
    vector<int> color(n,-1);

    for (int i =0; i<n;i++)
    {
        if(color[i]==-1)
        {
            queue<int> que;
            color[i]=0;
            que.push(i);


            while(!que.empty())
            {
                int vertex = que.front();
                que.pop();

                for (auto neighbor : graph[vertex])
                {
                    if(color[neighbor]==-1)
                    {
                         color[neighbor]=1-color[vertex];
                         que.push(neighbor);
                    }
                    else if(color[vertex]==color[neighbor])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // Example 1: Bipartite graph
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};
    adj[4] = {5};
    adj[5] = {4};

    if (isBipartite(adj, n)) {
        cout << "Graph is Bipartite ✅\n";
    } else {
        cout << "Graph is NOT Bipartite ❌\n";
    }

    return 0;
}