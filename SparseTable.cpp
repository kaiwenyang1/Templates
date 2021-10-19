#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Sparse{
	vector<int>logs;
	vector<vector<int>>dp;
	int ln;
	int size;
	void init(int n, vector<int>arr){
		size = n;
		logs.resize(n+1);
		dp.resize(n+1);
		ln = 0;
		for(int i = 1; i<=n; i*=2){
			logs[i] = ln; ln++;
		}
		for(int i = 1; i<=n; i++){
			dp[i].resize(ln+1);
			logs[i] = max(logs[i],logs[i-1]);
			dp[i][0] = arr[i];
		}
		for(int i = 1; i<=ln; i++){
			for(int j = 1; j+(1<<i)-1<=n; j++){
				dp[j][i] = min(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int query(int l, int r){
		int lg = logs[r-l+1];
		return min(dp[l][lg],dp[r-(1<<lg)+1][lg]);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	Sparse spt;
	vector<int>arr(n+1);
	for(int i = 1; i<=n; i++){
		cin >> arr[i];
	}
	spt.init(n,arr);
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << spt.query(l,r) << "\n";
	}
	return 0;
}
