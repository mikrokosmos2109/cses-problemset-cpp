#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define ll long long


int main()
{
    ll n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<int> temp;
    temp.push_back(v[0]);
    int ans = -1;
    for(int i=0; i<n; i++){
       if(v[i] > temp.back()){
        temp.push_back(v[i]);
       }else{
        int idx = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
        temp[idx] = v[i];
       }
    }
    cout<<temp.size()<<endl;

}
