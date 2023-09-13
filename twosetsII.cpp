#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll solve(ll i, ll target, vector<ll> &nums,vector<vector<ll>> &dp)
{
    if (i < 0 || target < 0)
    {
        return 0;
    }

    if (target == 0)
    {
        return 1;
    }

    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }
    ll pick = 0;
    if (target >= nums[i])
    {
        pick =solve(i - 1, target - nums[i], nums,dp);
    }
    ll notpick = solve(i - 1, target, nums,dp);
    return dp[i][target] = (pick + notpick) % MOD;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr;
    for (ll i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(n,vector<ll> (sum/2+1, -1));
    cout << solve(n - 1, sum / 2, arr, dp) % MOD << endl;
    return 0;
}
