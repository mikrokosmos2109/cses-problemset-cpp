#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int diff = x - arr[i];
        if (mp.find(diff) != mp.end())
        {
            cout << mp[diff] << " " << i + 1 << endl;
            return 0;
        }
        mp[arr[i]] = i+1;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
