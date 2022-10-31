#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e6 + 6;
int dp[mxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		dp[i] = 1e9;
		int i1 = i;
		while(i1){
			dp[i] = min(dp[i] , dp[i - i1 % 10] + 1);
			i1 /= 10;
		}
	}
	cout << dp[n] << endl;


	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
