#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // input.txt
    freopen("output.txt", "w", stdout); // output.txt
#endif

    int n, m;
    cin >> n >> m;

    vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <bool> vis(n , false);
    vector <int> par(n , -1e9);

    int st = -1, en = -1;


    auto dfs = [&](auto &self, int u, int p, vector <bool> &vis, vector <int> &par, vector <int> adj[]) -> bool {
        vis[u] = 1;
        par[u] = p;
        for (auto v : adj[u]){
            if (!vis[v]) {
                if (self(self, v, u, vis, par, adj)) return true;
            }
            else if (vis[v] and v != p){
                st = u, en = v;
                return true;
            }
        }
        return false;
    };

    bool ok = false;

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            ok |= dfs(dfs, i, -1, vis, par , adj);
            if (ok) break;
        }
    }

    if (!ok) cout << "IMPOSSIBLE" << endl;
    else{
        vector <int> res;
        res.push_back(st);
        while(st != en){
            st = par[st];
            res.push_back(st);
        }
        reverse(res.begin(), res.end());
        res.push_back(en);
        cout << res.size() << endl;
        for (int x : res){
            cout << x + 1 << ' ';
        }
        cout << endl;
    }



    return 0;
}
