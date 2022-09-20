#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
#ifndef ONLINE_JUDGE					
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();
		ll n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			ll val = i * i;
			ll total = val * (val - 1) / 2;
			ll ans = total - 4 * (i - 1)*(i - 2);
			cout << ans << endl;
		}

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
