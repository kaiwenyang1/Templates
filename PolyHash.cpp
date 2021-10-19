#include <bits/stdc++.h>
using namespace std;
#define int long long
struct PolyHash{
	/*
	WARNING: make sure the values in the array or string are in the range [0,5e8]
	*/
	vector<int>powers;
	vector<int>powers2;
	vector<int>hashes;
	vector<int>hashes2;
	int seed = 500002961;
	int seed2 = 500003263;
	const int mod = (int)1e9+7;
	const int mod2 = 998244353;
	vector<int>arr;
	void init(int n){
		powers.resize(n+5); powers[0] = 1;
		powers2.resize(n+5); powers2[0] = 1;
		hashes.resize(n+5);
		hashes2.resize(n+5);
		for(int i = 1; i<=n; i++){
			powers[i] = powers[i-1]*seed; powers[i]%=mod;
			powers2[i] = powers2[i-1]*seed2; powers2[i]%=mod2;
		}
		for(int i = 1; i<=n; i++){
			hashes[i] = hashes[i-1]*seed+arr[i]; hashes[i]%=mod;
			hashes2[i] = hashes2[i-1]*seed2+arr[i]; hashes2[i]%=mod2;
		}
	}
	void init(int n, string s){//string is 0 indexed
		arr.resize(n+5);
		for(int i = 1; i<=n; i++){
			arr[i] = s[i-1];
		}
		init(n);
	}
	void init(int n, vector<int>a){//a is 1 indexed
		arr.resize(n+5);
		for(int i = 1; i<=n; i++){
			arr[i] = a[i];
		}
		init(n);
	}
	pair<int,int> subhash(int l, int r){//inclusive
		int hsh = hashes[r]-hashes[l-1]*powers[r-l+1]%mod; hsh+=mod; hsh%=mod;
		int hsh2 = hashes2[r]-hashes2[l-1]*powers2[r-l+1]%mod2; hsh2+=mod2; hsh2%=mod2;
		return {hsh,hsh2};
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	string t;
	cin >> s >> t;
	PolyHash hsh;
	PolyHash hsh2;
	hsh.init(s.size(),s);
	hsh2.init(t.size(),t);
	int ans = 0;
	for(int i = t.size(); i<=s.size(); i++){
		if(hsh2.subhash(1,t.size())==hsh.subhash(i-t.size()+1,i)){
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
