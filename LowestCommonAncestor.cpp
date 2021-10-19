#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<int>>adj(mxn); int ln = 20;
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<int>lvl(mxn);
void dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if((1<<i)&dif){
			x = dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i = ln-1; i>=0; i--){
		if(dp[x][i]!=dp[y][i]){
			x = dp[x][i]; y = dp[y][i];
		}
	}
	return dp[x][0];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	return 0;
}
