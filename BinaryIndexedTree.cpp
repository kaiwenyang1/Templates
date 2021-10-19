#include <bits/stdc++.h>
using namespace std;
#define int long long
struct BIT{
	vector<int>arr;
	int size;
	void init(int n){
		size = n;
		arr.resize(n+5);
	}
	void update(int x, int val){
		for(int a = x; a<=size; a+=a&-a){
			arr[a]+=val;
		}
	}
	int query(int x){
		int sum = 0;
		for(int a = x; a>0; a-=a&-a){
			sum+=arr[a];
		}
		return sum;
	}
	void change(int x, int val){
		int v = query(x)-query(x-1);
		update(x,val-v);
	}
	int query(int x, int y){//inclusive
		return query(y)-query(x-1);
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,q;
	cin >> n >> q;
	BIT bit;
	bit.init(n);
	for(int i = 1; i<=n; i++){
		int x;
		cin >> x;
		bit.update(i,x);
	}
	while(q--){
		int cm;
		cin >> cm;
		if(cm==1){
			int i,v;
			cin >> i >> v;
			bit.change(i,v);
		}
		else{
			int a,b;
			cin >> a >> b;
			cout << bit.query(a,b) << "\n";
		}
	}
	return 0;
}
