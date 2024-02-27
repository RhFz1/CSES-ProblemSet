#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>

using namespace std;

#define ll long long
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}


const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

// vi g[N];
// int a[N];

// int mpow(int base, int exp)
// {
//     base %= mod;
//     int result = 1;
//     while (exp > 0)
//     {
//         if (exp & 1)
//             result = ((ll)result * base) % mod;
//         base = ((ll)base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }

// void ipgraph(int n, int m)
// {
//     int i, u, v;
//     while (m--)
//     {
//         cin >> u >> v;
//         u--, v--;
//         g[u].pb(v);
//         g[v].pb(u);
//     }
// }

// void dfs(int u, int par)
// {
//     for (int v : g[u])
//     {
//         if (v == par)
//             continue;
//         dfs(v, u);
//     }
// }

void selfDestruct(char *argv)
{
    char *process_name = argv;
    char command[256] = "rm ";
    strcat(command, process_name);
    system(command);
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // input.txt
    freopen("output.txt", "w", stdout); // output.txt
#endif

    // Your Code Goes Here.

    int n, m;
    cin >> n >> m;

    vector <int> adj[n];

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector <bool> vis(n ,false);

    vector <int> par(n , -1);

    auto bfs = [&](auto self, vector <bool> &vis , vector <int> &par, vector <int> adj[]) -> bool{
        queue <int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            if (u == n - 1) return true;

            for (auto v : adj[u]){
                if (!vis[v]){
                    par[v] = u;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        return false;
    };


    bool ok = bfs(bfs, vis , par, adj);
    if (!ok) cout << "IMPOSSIBLE" << endl;
    else {
        int v = n - 1;
        vector <int> res;
        res.push_back(v);
        while(v != 0) v = par[v], res.push_back(v);
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for (int x : res){
            cout << x + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}