#include <bits/stdc++.h>
using namespace std;
#define ll long long
// bool isPossible(vector<ll> &v, int mid){

// }
int main()
{
   ll n;
   cin>>n;
   vector<ll> v(n);
   for(int i=0; i<n; i++){
    cin>>v[i];
   }
   sort(v.begin(),v.end());
   ll ans = 1;

   for(int i=0; i<n; i++){
       if(v[i] > ans){
         break;
       }
       ans += v[i];
   }
   cout<<ans<<endl;

}
