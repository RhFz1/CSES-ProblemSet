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

    vector<pair <int , int>> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v , w});
    }


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


    for (int i = 0; i < n; i++) cout << dis[i] << ' ';
    cout << endl;

    return 0;
}
