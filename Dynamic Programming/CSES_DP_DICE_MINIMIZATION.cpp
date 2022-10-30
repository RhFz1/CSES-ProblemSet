#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int mxn = 1e6 + 5;

int dp[mxn];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n;
	cin >> n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for (int j = 1; j <= min(6 , i); j++){
			dp[i] = (dp[i] + dp[i - j]) % M;
		}
	}
	cout << dp[n] << endl;

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
