#include <bits/stdc++.h>
using namespace std;

// int solve(int ind, int maxx_price, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp)
// {
//     if (ind < 0 || maxx_price <= 0)
//     {
//         return 0;
//     }
//     if (dp[ind][maxx_price] != -1)
//         return dp[ind][maxx_price];

//     int take = 0;
//     if (prices[ind] <= maxx_price)
//     {
//         take = pages[ind] + solve(ind - 1, maxx_price - prices[ind], prices, pages, dp);
//     }

//     int nottake = solve(ind - 1, maxx_price, prices, pages, dp);

//     return dp[ind][maxx_price] = max(take, nottake);
// }

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(x + 1, 0));
    
    for(int i=prices[0]; i<=x; i++){
        dp[0][i] = pages[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int cap= 0; cap<=x; cap++){
            int nottake = dp[ind-1][cap];

            int take = 0;
            if(prices[ind] <= cap){
                take = pages[ind] + dp[ind-1][cap-prices[ind]];
            }
            dp[ind][cap] = max(take, nottake);
        }
        
    }
    // cout << solve(n - 1, x, prices, pages, dp) << endl;
    cout<<dp[n-1][x];
    return 0;
}
