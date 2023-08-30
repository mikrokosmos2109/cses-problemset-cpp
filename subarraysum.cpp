#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ll maxi =-9e18;;
    ll curr_sum = 0;
    for(int i=0; i<n; i++){
        curr_sum += v[i];

        if(curr_sum>maxi){
            maxi = curr_sum;
        }
        if(curr_sum <0){
            curr_sum = 0;
        }
    }
    cout<< maxi<<endl;
}
