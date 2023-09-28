#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char directions[] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y, int n, int m, vector<string> &maze)
{
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '#';
}

string findShortestPath(int n, int m, vector<string> &maze)
{
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
            else if (maze[i][j] == 'B')
            {
                endX = i;
                endY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[startX][startY] = true;

    vector<vector<int>> parent(n, vector<int>(m, -1));

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == endX && y == endY)
        {
            string path = "";
            while (x != startX || y != startY)
            {
                int px = parent[x][y];
                path += directions[px];
                x -= dx[px];
                y -= dy[px];
            }
            reverse(path.begin(), path.end());
            return "YES\n" + to_string(path.length()) + "\n" + path;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, n, m, maze) && !visited[newX][newY])
            {
                visited[newX][newY] = true;
                parent[newX][newY] = i;
                q.push({newX, newY});
            }
        }
    }

    return "NO";
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
    }

    string result = findShortestPath(n, m, maze);
    cout << result << endl;

    return 0;
}