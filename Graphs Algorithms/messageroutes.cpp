#include <bits/stdc++.h>
using namespace std;
#define ll long long

void bfs(vector<int> adj[], vector<int> &vis, vector<int> &parent){
    vis[1] = 1;
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        /* code */
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if(vis[it] == 0){
                vis[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    bfs(adj,vis,parent);

    if(parent[n] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    //now tracing back the path 
    //start from destination
    int parent_of_curr_node = n;
    stack<int> st;
    while (parent_of_curr_node != -1)
    {
        st.push(parent_of_curr_node); // first 5
        parent_of_curr_node = parent[parent_of_curr_node]; //n -> parent(n) -> parent(parent(n)) -> untill you reach 1
    }
    cout<<st.size()<<endl;
    while (!st.empty())
    {
        /* code */
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}
