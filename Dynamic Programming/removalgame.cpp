#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll i, ll  j, vector<ll> &nums,vector<vector<ll>> &dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        return nums[i];
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    ll take_ith = nums[i] + min(solve(i + 2, j, nums, dp), solve(i + 1, j - 1, nums, dp));
    ll take_jth = nums[j] + min(solve(i + 1, j - 1, nums, dp), solve(i, j - 2, nums, dp));

    return dp[i][j]=max(take_ith,take_jth);
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(n,-1));
    cout << solve(0, n - 1, arr, dp) << endl;
    return 0;
}
