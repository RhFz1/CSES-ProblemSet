#include <bits/stdc++.h>
using namespace std;

int factorial(int val){
	int ans = 1;
	for (int i = 2; i <= val; i++){
		ans *= i;
	}
	return ans;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	string s;
	cin >> s;
	vector <string> ans;
	sort(s.begin() , s.end());
	ans.push_back(s);
	while(next_permutation(s.begin() , s.end())){
		ans.push_back(s);
	}

	cout << ans.size() << endl;
	for(string i : ans){
		cout << i << endl;
	}

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

}
