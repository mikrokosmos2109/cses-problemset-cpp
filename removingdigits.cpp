#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count=0;
    
    while(n>0){
        int max_digit = 0;
        int temp = n;
        while(temp > 0){
            int digit = temp%10;
            max_digit = max(max_digit,digit);
            temp = temp/ 10;
        }
        n = n-max_digit;
        count++;
    }
    cout<<count<<endl;
    return 0;
}
