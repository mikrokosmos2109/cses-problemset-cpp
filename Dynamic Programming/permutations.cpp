#include <bits/stdc++.h>
using namespace std;

void permutations(string &s, int ind, set<string> &ans)
{
    int n = s.size();
    if (ind >= n)
    {
        ans.insert(s);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        if (i != ind && s[i] == s[ind])
        {
            continue;
        }
        swap(s[ind], s[i]);
        permutations(s, ind + 1, ans);
        swap(s[ind], s[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    set<string> ans;
    permutations(s, 0, ans);
    // sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (string str: ans)
    {
        cout << str << endl;
    }

    return 0;
}
