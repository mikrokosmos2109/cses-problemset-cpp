#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long

// int solve(ll ind, ll target, vector<ll> &v,vector<vector<int>> &dp){
//     if(ind == 0){
//         if(target % v[0] == 0){
//             return target/v[ind];
//         }else{
//             return INT_MAX;
//         }
//     }
//     if(dp[ind][target] != -1) return dp[ind][target];

//     ll nottake = solve(ind-1, target,v,dp);
//     ll take= INT_MAX;

//     if(v[ind] <= target){
//         take = 1+ solve(ind,target-v[ind],v,dp);
//     }

//     return dp[ind][target] = min(take,nottake);
// }

int main()
{
    ll n,target;
    cin>>n>>target;

    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<vector<int>> dp(n,vector<int> (target+1,0));
    for (int i = 0; i <= target; i++)
    {
        if ((i % v[0]) == 0)
        {
            dp[0][i] = i / v[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int amt = 0; amt <= target; amt++)
        {
            // notpick
            int notpick = dp[ind - 1][amt];

            int pick = 1e9;
            if (v[ind] <= amt)
            {
                pick = 1 + dp[ind][amt - v[ind]];
            }

            dp[ind][amt] = min(pick, notpick);
        }
    }
    int ans = dp[n - 1][target];
    if (ans >= 1e9){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
  
}
