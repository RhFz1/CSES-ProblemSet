#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 5;i <= n; i *= 5){
		ans += n / i;
	}
	cout << ans << endl;

	

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
