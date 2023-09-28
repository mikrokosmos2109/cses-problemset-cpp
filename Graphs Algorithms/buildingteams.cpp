#include <bits/stdc++.h>
using namespace std;

vector<int> color;

//BFS
bool isBipartite(int start, vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node])
        {
            if (color[neighbor] == -1)
            {
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    color.assign(n + 1, -1);

    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(i, adj))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << color[i]+1 << " ";
    }
    cout << endl;

    return 0;
}
//DFS
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> color;
// vector<int> visited;

// bool dfs(int node, int c, vector<vector<int>> &adj)
// {
//     visited[node] = 1;
//     color[node] = c;

//     for (int neighbor : adj[node])
//     {
//         if (!visited[neighbor])
//         {
//             if (!dfs(neighbor, 1 - c, adj))
//             {
//                 return false;
//             }
//         }
//         else if (color[neighbor] == color[node])
//         {
//             return false;
//         }
//     }

//     return true;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> adj(n + 1);

//     for (int i = 0; i < m; ++i)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     color.assign(n + 1, -1);
//     visited.assign(n + 1, 0);

//     for (int i = 1; i <= n; ++i)
//     {
//         if (!visited[i])
//         {
//             if (!dfs(i, 0, adj))
//             {
//                 cout << "IMPOSSIBLE" << endl;
//                 return 0;
//             }
//         }
//     }

//     for (int i = 1; i <= n; ++i)
//     {
//         cout << color[i] + 1 << " ";
//     }
//     cout << endl;

//     return 0;
// }
