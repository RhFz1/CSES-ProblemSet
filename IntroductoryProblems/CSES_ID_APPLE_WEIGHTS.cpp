/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ll n;
    cin >> n;
    vector <ll > v(n);
    ll dp[n];
    for(auto &i : v) cin >> i;
    ll sum = accumulate(v.begin() , v.end() , 0);
    if (n == 1){
        cout << sum << endl;
        return 0;
    }
    
    bool flag = false;
    if (sum & 1){
        flag = true;
    }
    ll target = sum / 2;
    
    for (ll i = 0; i < n; i++){
        ll closest = v[i] - target;
        ll temp = v[i] - target;
        bool flag_1 = false;
        for(ll j = 0; j < i; j++){
            if (abs(dp[j] + v[i]) <= abs(closest)){
                flag_1 = true;
                temp = dp[j];
                closest = abs(dp[j] + v[i]);
            }
        }
        if (flag_1){
            dp[i] = temp + v[i];
        }else{
            dp[i] = temp;
        }
    }
    ll min_val = 1e9;
    for(ll i = 0; i < n; i++){
        min_val = min(min_val , abs(dp[i]));
    }
    if (flag){
        cout << sum - 2 * (target - min_val);
    }else{
        cout << 2 * min_val << endl;
    }
    

    return 0;
}
