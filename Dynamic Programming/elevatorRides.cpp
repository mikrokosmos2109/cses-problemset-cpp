// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll n,x;
//     cin >> n>>x;
//     int count=0;
//     int sum = 0;
//     vector<int> v(n);
//     for(int i=0; i<n; i++){
//         cin>>v[i];
//     }
//     for(int i=0; i<n; i++){
//         if(sum + v[i] <=x ){
//             sum = sum+v[i];
//         }else{
//             count++;
//             sum = v[i];
//         }
//     }
//     if(sum>0){
//         count++;
//     }
    
//     cout<<count<<endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<pair<int, int>> dp(1 << n, {INF, INF});
    dp[0] = {0, 0};

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                continue;
            int nmask = mask | (1 << i);

            if (dp[mask].second + a[i] > m)
            {
                dp[nmask] = min(dp[nmask], make_pair(dp[mask].first + 1, a[i]));
            }
            else
            {
                dp[nmask] = min(dp[nmask], make_pair(dp[mask].first, dp[mask].second + a[i]));
            }
        }
    }

    int ans = dp.back().first;
    int cur = dp.back().second;
    if (cur > 0)
        ans++;
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
