#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define Fi(a,n) for(int i = a; i < n; i++)
#define Fd(n,a) for(int i = n; i >= a; i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define pb push_back
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define read(a) for (int i = 0; i<sz(a); i++) cin >> a[i]
const ll mod = 1e9 + 7;
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	read(a);
	n+=1;
	for (auto i: a){
		cout << n - i << " ";
	}

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}