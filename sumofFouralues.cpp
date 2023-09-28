#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = i + 1; j < n - 2; ++j)
        {
            int left = j + 1;
            int right = n - 1;
            int target = x - arr[i].first - arr[j].first;

            while (left < right)
            {
                int current_sum = arr[left].first + arr[right].first;

                if (current_sum == target)
                {
                    cout << arr[i].second << " " << arr[j].second << " " << arr[left].second << " " << arr[right].second << endl;
                    return 0;
                }
                else if (current_sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
