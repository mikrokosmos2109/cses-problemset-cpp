#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll t;
    cin>>t;
    set<ll> st;
    while(t--){
        ll n;
        cin >> n;


        if(st.size() == 0){
            st.insert(n);
            continue;
        }
        vector<ll> temp;
        for(auto it: st){
            temp.push_back(it+n);
        }
        st.insert(n);
        for(int i=0; i<temp.size(); i++){
            st.insert(temp[i]);
        }

    }
    cout << st.size() << endl;
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
