// #include <iostream>
// #include <vector>
// #include <queue>
// #include <cstring>

// using namespace std;

// const int MOD = 1e9 + 7;
// const int MAXN = 100005;



// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> adj[n+1];
//     vector<int> indegree(n + 1, 0);
//     vector<int> ways(n + 1, 0);
//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         indegree[b]++;
//     }

//     queue<int> q;


//     for (int i = 2; i <= n; i++)
//     {
//         if (indegree[i] == 0)
//             q.push(i);
//     }
//     //topo sort will start form node 1
//     q.push(1);   // Start from level 1
//     ways[1] = 1; // There's only one way to reach level 1

//     while (!q.empty())
//     {
//         int level = q.front();
//         q.pop();

//         for (int neighbor : adj[level])
//         {
//             indegree[neighbor]--;
//             ways[neighbor] = (ways[neighbor] + ways[level]) % MOD;

//             if (indegree[neighbor] == 0 && neighbor != 1)
//             {
//                 q.push(neighbor);
//             }
//         }
//     }

//     cout << ways[n] << endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main(){

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    vector<int> indegree(n+1,0);
    vector<int> ways(n+1,0);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;

    for(int i=2; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //topo sort will start from i=1
    q.push(1);
    ways[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adjNode: adj[node]){
            indegree[adjNode]--;
            ways[adjNode] = (ways[adjNode] + ways[node])%mod;

            if (indegree[adjNode] ==0 && adjNode != 1){
                q.push(adjNode);
            }  
        }
    }
    cout<<ways[n]<<endl;
    return 0;
}
