#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e3 + 5;
const int M = 1e9 + 7;
int dp[mxn][mxn];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
 	dp[0][0] = 1;
 	for (int i = 0; i < n; i++){
 		for (int j = 0; j < n; j++){
 			if (i){
 				dp[i][j] += dp[i - 1][j];
 			}
 			if (j){
 				dp[i][j] += dp[i][j - 1];
 			}
 			dp[i][j] %= M;
 			if (s[i][j] == '*') dp[i][j] = 0;
 		}
 	}
 	cout << dp[n - 1][n - 1] << endl;

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
