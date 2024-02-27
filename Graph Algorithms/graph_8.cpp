#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // input.txt
    freopen("output.txt", "w", stdout); // output.txt
#endif

    int n, m, q;
    cin >> n >> m >> q;

    vector <vector <long long>> adj(n , vector <long long> (n , 1e15));

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u][v] = min({1LL *w , adj[u][v] , adj[v][u]});
        adj[v][u] = min({1LL * w , adj[u][v] , adj[v][u]});
    }

    vector <vector <long long>> d(n , vector <long long> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) d[i][j] = d[j][i] = 0;
            else{
                d[i][j] = d[j][i] = adj[i][j];
            }
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (d[u][v] >= 1e15 ? -1 : d[u][v]) << endl;
    }

    return 0;
}
