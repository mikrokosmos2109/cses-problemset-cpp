#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long

ll minWeightDifference(ll idx, ll currDiff, ll totalWeight, vector<ll> &weights)
{
    if (idx == 0)
    {
        return abs(totalWeight - 2 * currDiff);
    }

    // Include the current weight in the first group
    ll diff1 = minWeightDifference(idx - 1, currDiff + weights[idx - 1], totalWeight, weights);

    // Include the current weight in the second group
    ll diff2 = minWeightDifference(idx - 1, currDiff, totalWeight, weights);

    return min(diff1, diff2);
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> weights(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    ll totalWeight = 0;
    for (ll weight : weights)
    {
        totalWeight += weight;
    }

    ll result = minWeightDifference(n, 0, totalWeight, weights);
    cout << result << endl;

    return 0;
}
