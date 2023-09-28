#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> toposort(vector<int> adj[], int n){
    vector<int> indegree(n+1,0);
    queue<int> q;

    vector<int> ans;
    //calc indegrees of every node
    for(int i=1; i<= n; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    //push into queue having indegree 0
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    // now bfs
    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return ans;
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
    }
    vector<int> ans = toposort(adj,n);
    if(ans.size() == n){
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
        
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
