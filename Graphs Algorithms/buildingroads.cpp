#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<int> adj[], vector<int> &vis, int src)
{
    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (vis[it] == 0)
        {
            dfs(adj, vis, it);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    vector<vector<int>> grid(m, vector<int>(2));
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }
    
    vector<int> vis(n+1,0);
    vector<int> ans;
    int count=0;
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            dfs(adj,vis,i);
            ans.push_back(i);
            count++;
        }
    }
    cout<<count-1<<endl;
    for(int i=1; i<ans.size(); i++){
        cout<<ans[i-1] << " "<<ans[i]<<endl; 
    }
    // cout<<endl;
    return 0;
}
