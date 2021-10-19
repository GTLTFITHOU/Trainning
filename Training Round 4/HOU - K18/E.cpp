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

const int maxn = 1e5 + 5;

int a[maxn], bott[maxn], topp[maxn];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i];
	}
	topp[n - 1] = r;
	bott[n - 1] = l;

	bool no_ans = false;

	for (int i = n - 2 ; i >= 0; i--) {
		topp[i] = topp[i+1];
		bott[i] = bott[i+1];
		if(a[i] < a[i+1]){
			topp[i]--;
			bott[i] = max(l,bott[i]-k);
		}
		if(a[i] > a[i+1]){
			topp[i] = min(r,topp[i] + k);
			bott[i]++;
		}
		if(l > topp[i] || bott[i] > r){
			no_ans = true;
		}
	}

	if(no_ans){
		cout<<-1<<endl;
	}else{
		int cur = bott[0];
		cout<<cur<<" ";
		for(int i = 1 ; i < n ; i++){
			if(a[i-1] < a[i]){
				cur = bott[i] <= cur+1 && cur+1 <= topp[i] ? cur+1 : bott[i];
			}
			if(a[i-1] > a[i]){
				cur = bott[i] <= cur-k && cur-k <= topp[i] ? cur-k : bott[i];
			}
			cout<<cur<<" ";
		}
	}

}