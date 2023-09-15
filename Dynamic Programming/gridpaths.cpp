#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long

ll solve(vector<vector<char>> &v, int i, int j, vector<vector<ll>> &dp)
{
    if (i < 0 || j < 0 || v[i][j] == '*')
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    ll right = 0, down = 0;
    if (j > 0)
    {
        right = solve(v, i, j - 1, dp) % mod;
    }
    if (i > 0)
    {
        down = solve(v, i - 1, j, dp) % mod;
    }

    return dp[i][j] = (right + down) % mod;
}

int main()
{
    ll n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    cout << solve(v, n - 1, n - 1, dp) << endl;
}
