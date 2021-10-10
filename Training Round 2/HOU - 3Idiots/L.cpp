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
    int n;cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mp[a[i]]=i;
    }
    int cnt=1;
    for(int i=1;i<n;++i){
        if(mp[i] > mp[i+1]) ++cnt;
    }
    int l2= log2(cnt);
    cout<<(l2+ ((1<<l2)<cnt));
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
