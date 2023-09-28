#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dijkstra(ll V, vector<vector<pair<ll, ll>>> &adj)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(V + 1, LLONG_MAX);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto a = pq.top();
        ll node = a.second;
        ll distance = a.first;
        pq.pop();
        if (distance > dist[node])
            continue; // Skip outdated distances
        for (auto it : adj[node])
        {
            ll v = it.first;
            ll w = it.second;
            if (distance + w < dist[v])
            {
                dist[v] = distance + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (ll i = 0; i < m; ++i)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<ll> dist = dijkstra(n, adj);

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
