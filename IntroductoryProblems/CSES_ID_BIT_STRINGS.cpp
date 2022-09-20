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
	ll ans = 1;
	for (int i = 0; i < n; i++){
		ans = 2 * ans % ((int)1e9 + 7);
	}
	cout << ans << endl;

	

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
