//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int find(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        return grid[i][j];
    }
    
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int key)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return 0;
        grid[i][j] = key;
        return dfs(i, j + 1, n, m, grid, key) + dfs(i + 1, j, n, m, grid, key) + dfs(i, j - 1, n, m, grid, key) + dfs(i - 1, j, n, m, grid, key) + 1;
    }
    
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int mx = 0;
        map <int, int> mp;
        int n = grid.size(), m = grid[0].size(), key = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    key++;
                    mp[key] = dfs(i, j, n, m, grid, key);
                    mx = max(mp[key], mx);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    set <int> keys;
                    keys.insert(find(i + 1, j, grid));
                    keys.insert(find(i - 1, j, grid));
                    keys.insert(find(i, j + 1, grid));
                    keys.insert(find(i, j - 1, grid));
                    int area = 1;
                    for(auto it: keys) 
                        area += mp[it];
                    mx = max(mx, area);
                }
            }
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends