#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

const int maxn = 2e4 + 5;

int x[maxn];
int l,d,n;

int cal(int l, int r){
	r-= d;
	if (r<=l) return 0;
	return (r - l)/d;
}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>l>>d>>n;
	for(int i = 0 ; i < n ; i ++){
		cin>>x[i];
	}
	sort(x,x+n);
	vector<int> src;
	int ans = 0;

	if(n >= 1){
		if( 6 + d <= x[0]){
			ans ++;
			src.epb(6);
		}
	}else{
		if( 6 + 6 <= l){
			ans ++;
			src.epb(6);
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		src.epb(x[i]);
	}

	if(n >= 1){
		if( x[n-1] <= l - 6 - d){
			ans ++;
			src.epb(l - 6);
		}
	}else{
		if( 0 <= l - 6 - 6 &&  l - 6 != 6){
			ans ++;
			src.epb(l - 6);
		}
	}


	for(int i = 0 ; i < sz(src) - 1 ; i++){
		ans += cal(src[i] , src[i+1]);
	}

	cout<<ans<<endl;
}