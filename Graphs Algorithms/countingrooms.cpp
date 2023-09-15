#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<vector<char>> &grid, int i, int j){
    int n = grid.size();
    int m = grid[0].size();

    if(i<0 || j<0 || i>=n || j>=m) return;
    if(grid[i][j] == 'k' || grid[i][j] == '#'){
        return;
    }

    grid[i][j] = 'k';
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
}
int solve(vector<vector<char>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.'){
                dfs(grid,i,j);
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    cout<<solve(grid)<<endl;
    return 0;
}
