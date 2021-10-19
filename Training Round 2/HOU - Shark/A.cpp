#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define ntest 0
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = (int) 1e9 + 7;
int t;
void solve(){
    int l , d, n; cin >> l >> d >> n;
    if(l < 12){
        cout << 0;
        return;
    }
    l -= 12;
    int a[n + 10];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] -= 6;
    }
    sort(a, a + n + 1);
    ll tong = 0;
    for(int i = 1; i < n; i++){
        tong += ((a[i] - a[i - 1] - d) / d);
    }
    if(n != 0){
        tong += (a[0] / d);
        tong += (l - a[n - 1]) / d;
        cout << tong;
    }
    else{
        cout << l / d + 1;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(ntest){
    cin>>t;
    while(t--)
        solve();
    }
    else{
    solve();
    }
}