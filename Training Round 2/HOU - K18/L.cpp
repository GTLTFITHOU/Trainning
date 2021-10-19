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
const int maxn = 1e6 + 5;
int a[maxn];
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	map<int,int> mp;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		mp[a[i]] = i;
	}
	
	int cur = 1;
	int cnt = 1;
	while(true){
		if(cur >= n ) break;
		int nxIdx = mp[cur + 1 ];
		if (nxIdx < mp[cur]){
			cnt++;
			// show(cur);
		}
		cur ++;
	}
	// show(cnt);
	int l2 = log2(cnt);
	cout<< l2 + ( (1<<l2) < cnt ) <<endl;
}