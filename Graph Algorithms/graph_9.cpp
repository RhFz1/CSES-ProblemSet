#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2.5e3 + 1;
vector <pair <int , int>> adj[N];
vector <int> adjk[N];
vector <ll> d(N , 1e17);

bool vis1[N] , vis2[N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++){
		int u, v , w;
		cin >> u >> v >> w;

		--u, --v;
		adj[u].push_back({v , -w});
		adjk[v].push_back(u);
	}


	auto dfss = [&] (auto &self, int u)->void{
		vis1[u] = 1;
		for (auto p : adj[u]){
			if (!vis1[p.first]){
				self(self, p.first);
			}
		}
	};
	auto dfse = [&] (auto &self, int u) -> void{
		vis2[u] = 1;
		for (auto v : adjk[u]){
			if (!vis2[v]){
				self(self, v);
			}
		}
	};

	dfss(dfss , 0);
	dfse(dfse , n - 1);

	d[0] = 0;

	for (int i = 0; i < n - 1; i++){
		for (int u = 0; u < n; u++){
			for (auto p : adj[u]){
				if (d[u] >= 1e17) continue;
				int v = p.first , w = p.second;
				if (d[v] > d[u] + w) d[v] = d[u] + w; 
			}
		}
	}

	bool ok = false;

	for (int u = 0; u < n; u++){
		for (auto p : adj[u]){
			int v = p.first, w = p.second;
			if (d[v] >= 1e17) continue;
			if (d[v] > d[u] + w and vis1[v] and vis2[v]){
				ok = true;
			}
		}
	}

	if (ok) cout << -1 << endl;
	else cout << -1LL * d[n - 1] << endl;

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
