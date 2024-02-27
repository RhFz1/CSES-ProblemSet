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






int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);   // input.txt
    freopen("output.txt", "w", stdout); // output.txt
#endif

    // Your Code Goes Here.
    int n , m;

    cin >> n >> m;

    vector <string> s(n);

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }


    int dx[] = {-1 , 0 , 1, 0}, dy[] = {0, 1, 0 , -1};

    unordered_map <int , char> mp;
    mp[0] = 'U';
    mp[1] = 'R';
    mp[2] = 'D';
    mp[3] = 'L';



    string ans = "";


    auto dfs = [&](auto self , int i , int j) -> bool {
        if (s[i][j] == 'B') return true;
        s[i][j] = '#';
        for (int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if (ni < n and ni > -1 and nj < m and nj > -1 and (s[ni][nj] == '.' || s[ni][nj] == 'B')){
                ans += mp[k];
                if (self(self , ni , nj)){
                    return true;
                }
            }
        }
        ans.pop_back();
        return false;
    };

    vector <vector <int>> vis(n , vector <int> (m , 0));
    int bx, by, ax, ay;

    auto bfs = [&](auto self, int i , int j) -> bool{
        queue <pair<int , int>> q;
        q.push({i , j});

        while(!q.empty()){
            pair <int , int> temp = q.front();
            int i = temp.first , j = temp.second;

            q.pop();
            if (s[i][j] == 'B') {
                bx = i, by = j;
                return true;
            }
            s[i][j] = '#';

            for (int k = 0; k < 4; k++){
                int ni = i + dx[k], nj = j + dy[k];
                if (ni < n and ni > -1 and nj < m and nj > -1 and (s[ni][nj] == '.' || s[ni][nj] == 'B')){
                    vis[ni][nj] = k;
                    q.push({ni, nj});
                }
            }
        }
        return false;
    };


    bool ok = false;

    

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == 'A') {
                ax = i, ay = j;
                ok = bfs(bfs, i , j);
                break;
            }
        }
    }

    if (ok){
        cout << "YES" << endl;
        string ans = "";
        while(true){
            int mv = vis[bx][by];
            ans += mp[mv];
            if (mv == 0 || mv == 2) bx = (bx + (mv == 0 ? 1 : -1));
            if (mv == 1 || mv == 3) by = (by + (mv == 1 ? -1 : 1));
            if (ax == bx and by == ay) break;
            //cout << bx << ' ' << by << endl;
        }
        reverse(all(ans));
        cout << ans.size() << endl;
        cout << ans << endl;

    }else cout << "NO" << endl;

    return 0;
}