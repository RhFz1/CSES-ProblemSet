#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e3 + 3 , mxx = 1e5 + 5;
int dp[mxx];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n , x;
	cin >> n >> x;
	int h[n] , s[n];
	for (int i = 0; i < n; i++){
		cin >> h[i];
	}
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	/*
		First Approach
	*/
	
	// for (int i = 1; i <= n; i++){
	// 	for (int j = 1; j <= x; j++){
	// 		if (j - h[i - 1] >= 0){
	// 			dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - h[i - 1]] + s[i - 1]);
	// 		}else{
	// 			dp[i][j] = dp[i - 1][j];
	// 		}
	// 	}
	// }
	// cout << dp[n][x] << endl;

	/*
		Second Approach
	*/
	// for (int i = 0; i < n; i++){
	// 	for (int j = x; j >= h[i]; j--){
	// 		dp[j] = max(dp[j - h[i]] + s[i] , dp[j]);
	// 	}
	// }
	// cout << dp[x] << endl;


	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
