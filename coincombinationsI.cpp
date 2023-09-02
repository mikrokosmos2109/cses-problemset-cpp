#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int solve(vector<int> &dp, vector<int> &a, int x)
{
    if (x == 0)
        return 1;
    if (x < 0)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    int ans = 0;
    for (int i = 0; i < a.size(); i++)
    {
        ans += solve(dp, a, x - a[i]);
        ans %= mod;
    }

    return dp[x] = ans;
}

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(x + 1, -1);

    cout << solve(dp, a, x);

    return 0;
}