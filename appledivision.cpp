#include <bits/stdc++.h>
using namespace std;


int main()
{
   int n;
   cin>>n;
   vector<int> v(n);
   for(int i=0; i<n; i++){
    cin>>v[i];
   }
   int i=0;
   int j=n-1;
    int sum1 = 0, sum2 =0;
    sort(v.begin(),v.end());
    while(i<j){
        sum1 += v[i] + v[j];
        sum2 += v[i+1] + v[j-1];

        i++;
        j--;
    }
    if (sum1 > sum2)
    {
        sum2 += v[n / 2];
    }
    else
    {
        sum1 += v[n / 2];
    }
    cout<<abs(sum1-sum2)<<endl;
    return 0;
}
