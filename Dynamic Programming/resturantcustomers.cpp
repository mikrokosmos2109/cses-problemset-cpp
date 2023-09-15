#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> events; // {time, event_type}

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        events.push_back(make_pair(a, 1));  // Arrival event
        events.push_back(make_pair(b, -1)); // Departure event
    }

    sort(events.begin(), events.end()); // Sort events based on time

    int max_customers = 0;
    int current_customers = 0;

    for (int i = 0; i < events.size(); ++i)
    {
        current_customers += events[i].second;
        max_customers = max(max_customers, current_customers);
    }

    cout << max_customers << endl;

    return 0;
}
