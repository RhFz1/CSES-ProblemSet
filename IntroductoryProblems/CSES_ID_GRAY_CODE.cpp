#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	clock_t z = clock();

	int n;
	cin >> n;
	map <int , vector <string>> mp;
	for(int i = 0; i < (1 << n); i++){
		string s = "";
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if ((1 << j) & i){
				s += '1';
				cnt++;
			}else{
				s += '0';
			}
		}
		mp[cnt].push_back(s);
	}
	for (int i = 0; i < n; i++){
		sort(mp[i].begin() , mp[i].end());
	}
	for (auto itr : mp){
		for (string val : itr.second){
			cout << val << ' '; 
		}
		cout << endl;
	}

		

	

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
	

}
