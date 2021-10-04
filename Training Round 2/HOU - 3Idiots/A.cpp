#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 3/10/2021
* @contest: Training Round 2 - CLB GTLT
**/
using namespace std;
typedef   long long ll;
typedef   pair<int,int> ii;
typedef   vector<ii> vii;
typedef   unsigned long long ull;
#define ins(x)  insert(x);
#define endl  '\n'
#define tup tuple<int,int,int>
#define pb push_back
#define rsz resize
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define debug(n) cout<<(n)<<" "
#define debugn(n) cout<<(n)<<"\n";
// sortpair(v) sort(v.begin(), v.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) { return left.second < right.second; });
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;

void solve()
{
    ll l,d,n;
    cin>>l>>d>>n;
    vector<ll> a(n);
    for(auto &i : a) cin>>i;
    if(l<12) {
        cout<<0<<endl;
        return;
    }
    if(n==0){
        cout<<((l-12)/d +1)<<endl;
        return;
    }

    ll res=0;
    sort(all(a));
    if(a[0]-6 >= d){
        ++res;
        a.pb(6);
    }
    sort(all(a));
    if( l-6 - a[sz(a)-1] >=d ){
        ++res;
        a.pb(l-6);
    }
    for(int i=1;i<sz(a);++i){
         ll x= (a[i]-a[i-1])/d ;
        if(x){
            res+=x-1;
        }
    }
    cout<<res<<endl;

}
void huykhanh(){
    int T;
    //cin>>T;
    T=1;
    while(T--) solve();
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    huykhanh();
return 0;
}
