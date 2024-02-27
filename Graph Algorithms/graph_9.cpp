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

    vector <pair <int, int>> adj[n];

    for (int i = 0; i < m; i++){
        int u, v , w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v , -w});
    }

    vector <int> d(n , 1e8);

    for (int i = 0; i < n - 1; i++){
        for (int u = 0; u < n; u++){
            for (auto p : adj[i]){
                int w = p.second, v = p.first;
                if (d[v] > d[u] + w){
                    d[v] = d[u] + w;
                } 
            }
        }
    }

    bool ok = false;

    for (int u = 0; u < n; u++){
        for (auto p : adj[u]){
            int w = p.second, v = p.first;
            if (d[v] > d[u] + w){
                ok = true;
                break;
            } 
        }
        if (ok) break;
    }

    if (ok) cout << -1 << endl;
    else {
        vector <long long> dis(n , 1e18);
        dis[0] = 0;


        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, 0});
        while(!pq.empty()){
            int u = pq.top().second;
            long long d_v = pq.top().first;
            pq.pop();
            if (d_v != dis[u]) continue;
            for (auto p : adj[u]){
                int to = p.first, d = p.second;
                if (dis[to] > dis[u] + d) {
                    dis[to] = dis[u] + d;
                    pq.push({dis[to], to});
                } 
            } 
        }

        cout << -dis[n - 1] << endl;
    }





    return 0;
}
