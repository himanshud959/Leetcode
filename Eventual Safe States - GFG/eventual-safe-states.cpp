//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  #define append push_back
    bool dfs(int i, vector<int> g[], vector<bool> &vis, vector<bool> &v){
        vis[i] = true;
        if (g[i].size()==0) return v[i] = true;
        bool ok=true;
        for(auto child: g[i]){
            if (vis[child]) {
                if (!v[child]) return false;
            }
            ok &= dfs(child, g, vis, v);
        }
        return v[i] = ok;
    }
    vector<int> eventualSafeNodes(int n, vector<int> g[]) {
        vector<bool> vis(n, false);
        vector<bool> v = vis;
        for(int i=0; i<n; i++){
            if (!vis[i]) dfs(i, g, vis, v);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if (v[i]) ans.append(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends