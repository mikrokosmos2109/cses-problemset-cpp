// #include <bits/stdc++.h>
// using namespace std;

// const int mod = 1e9 + 7; 

// long long no_of_ways(long long sum, int i, vector<int> &cns, vector<vector<int>> &dp)
// {

//     if (sum == 0)
//         return 1;

//     if (sum < 0 or i < 0)
//         return 0;

//     if (dp[sum][i] != -1)
//         return dp[sum][i];

//     long long op1 = no_of_ways(sum, i - 1, cns, dp);
//     long long op2 = no_of_ways(sum - cns[i], i, cns, dp);

//     dp[sum][i] = (op1 % mod + op2 % mod) % mod;
//     return dp[sum][i];
// }

// int main()
// {
//     long long n, s;
//     cin >> n >> s;

//     vector<int> cns(n);
//     for (int i = 0; i < n; ++i)
//         cin >> cns[i];

//     sort(cns.begin(), cns.end(), greater<int>());

//     vector<vector<int>> dp(s + 1, vector<int>(cns.size(), -1));
//     long long ans = no_of_ways(s, cns.size() - 1, cns, dp);

//     cout << ans << "\n";
// }

//BOTTOM UP APPROACH
#include <bits/stdc++.h>
#define ll long long

#define fr(a, b) for (int i = a; i < b; i++)
#define mod 1000000007
using namespace std;

int main()
{
    // fast_io;
    ll t, n, m, x, i, j, k, q;
    // cin >> t;
    t = 1;
    while (t--)
    {
        cin >> n >> x;
        vector<int> v(n + 1);
        fr(1, n + 1)
                cin >>
            v[i];
        int dp[n + 1][x + 1];

        for (int i = 1; i <= n; i++)
        {
            for (int sum = 0; sum <= x; sum++)
            {
                if (sum == 0)
                    dp[i][sum] = 1;
                else
                {
                    int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                    int op2 = (i == 1) ? 0 : dp[i - 1][sum];
                    dp[i][sum] = (op1 + op2) % mod;
                }
            }
        }

        cout << dp[n][x];
    }
    return 0;
}