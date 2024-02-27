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


    vector <string> s(n);

    for (int i = 0; i < n; i++){
        cin >> s[i];
    }


    vector <vector <int>> ts(n, vector <int> (m , 1e8));
    vector <vector <bool>> vis(n , vector <bool> (m , false));


    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

    auto valid = [&](auto &self, int r , int c) -> bool {
        if (r < n and r >= 0 and c < m and c >= 0) return true;
        return false;
    };


    queue <pair <int , int>> q;
    int ax , ay;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (s[i][j] == 'M'){
                q.push({i , j});
                ts[i][j] = 0;
                vis[i][j] = 1;
            }
            if (s[i][j] == 'A') ax = i , ay = j;
        }
    }

    auto bfsMark = [&](auto &self)->void{

        while(!q.empty()){
            pair <int, int> temp = q.front();
            int r = temp.first , c = temp.second;
            q.pop();
            for (int k = 0; k < 4; k++){
                int nr = dx[k] + r, nc = dy[k] + c;
                if (valid(valid, nr, nc) and s[nr][nc] != '#' and !vis[nr][nc]){
                    // cout << nr + 1 << ' ' << nc + 1 << ' ' << t + 1 << endl;
                    ts[nr][nc] = ts[r][c] + 1;
                    q.push({nr , nc});
                    vis[nr][nc] = 1;
                }
            }
        }
    };

    

    int lx = -1, ly = -1;


    vector <vector <int>> mat(n , vector <int> (m , 0));
    

    auto bfsRun = [&](auto self)->bool{
        queue <pair <int , int>> q;

        q.push({ax , ay});
        vector <vector <bool>> vis(n , vector <bool> (m , false));
        vis[ax][ay] = 1;

        int t = 1;
        while(!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                pair <int , int> temp = q.front();
                int r = temp.first , c = temp.second;
                // cout << r + 1 << ' ' << c + 1 << endl;
                
                if (r == n - 1 || c == m - 1 || r == 0 || c == 0) {
                    lx = r , ly = c;
                    return true;
                }
                q.pop();
                for (int k = 0; k < 4; k++){
                    int nr = r + dx[k], nc = c + dy[k];
                    if (valid(valid, nr , nc) and ts[nr][nc] > t and s[nr][nc] == '.' and !vis[nr][nc]){
                        // cout << nr + 1 << ' ' << nc + 1 << ' ' << k << endl;
                        mat[nr][nc] = k;
                        vis[nr][nc] = 1;
                        q.push({nr , nc});
                    }
                }
            }
            t++;
        }
        return false;
    };
    bfsMark(bfsMark);

    bool ok = bfsRun(bfsRun);

    unordered_map <int, char> mp;
    mp[0] = 'U', mp[1] = 'R', mp[2] = 'D', mp[3] = 'L';


    if (!ok) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        vector <char> res;
        while(s[lx][ly] != 'A'){
            int k = mat[lx][ly];
            res.push_back(mp[k]);
            if (k == 0) lx++;
            else if (k == 1) ly--;
            else if (k == 2) lx--;
            else ly++;
            
        }
        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        for (char c : res){
            cout << c;
        }
        cout << endl;
    }







    return 0;
}
