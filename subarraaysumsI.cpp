#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,x;
    cin >> n>>x;
    // int count=0;
    // int sum = 0;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    ll presum = 0;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        presum += v[i];
        ll needtoremove = presum - x;

        if(mp.find(needtoremove) != mp.end()){
            ans += mp[needtoremove];
        }
        mp[presum]++;
    }
    cout<<ans<<endl; 
    return 0;
}
