#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getNextIndex(vector<vector<ll>> &array, ll l, ll currentJobEnd)
{
    ll n=array.size();
    ll r = n - 1;

    ll result = n + 1;

    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (array[mid][0] > currentJobEnd)
        { // we can take this task
            result = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return result;
}
ll solve( ll ind, vector<vector<ll>> &arr,vector<ll> &dp)
{
    int n=arr.size();

    if(ind>=n) return 0;
    if(dp[ind] != -1) return dp[ind];

    // ll nextind = lower_bound(arr.begin(), arr.end(), vector<ll>{arr[ind][1], 0, 0}) - arr.begin();

    ll nextind = getNextIndex(arr, ind + 1, arr[ind][1]);
    ll pick = arr[ind][2] + solve(nextind, arr, dp);

    ll notpick = 0 + solve(ind+1,arr,dp);

    return dp[ind] = max(pick,notpick);
}

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    for (int i = 0; i < n; i++)
    {
        ll a,b,p;
        cin>>a>>b>>p;
        arr[i][0] = a;
        arr[i][1] = b;
        arr[i][2] = p;
    }
    sort(arr.begin(),arr.end());
    vector<ll> dp(n,-1);
    // ll ind = 0;
    cout<<solve(0,arr,dp)<<endl;

    return 0;
}
