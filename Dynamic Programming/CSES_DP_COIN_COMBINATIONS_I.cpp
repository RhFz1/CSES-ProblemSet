#include <bits/stdc++.h>
using namespace std;

const int mxx = 1e6 + 6;

const int M = 1e9 + 7;

int dp[mxx]; 

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n , x;
	cin >> n >> x;

	int c[n];
	for (int i = 0; i < n; i++){
		cin >> c[i];
	}
	dp[0] = 1;

	for (int i = 1; i <= x; i++){
		for (int j = 0; j < n; j++){
			if (i - c[j] >= 0){
				dp[i] = (dp[i] + dp[i - c[j]]) % M;
			}
		}
	}
	cout << dp[x] << endl;

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
