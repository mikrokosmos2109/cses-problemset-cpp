#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

ll solve(ll target,vector<ll> &dp){
   if(target<0){
    return 0;
   }
   if(target==0){
    return 1;
   }
   if(dp[target] != -1){
    return dp[target];
   }
   ll ways = 0;
   for(int i=1; i<=6; i++){
    ways = (ways +  solve(target-i,dp))%mod;
   }
   return dp[target] = ways;
}

int main() {
    ll n;
    cin >> n;
    // vector<ll> arr = {1, 2, 3, 4, 5, 6};
    vector<ll> dp(n+1,-1);
    cout << solve(n,dp);
    return 0;
}
