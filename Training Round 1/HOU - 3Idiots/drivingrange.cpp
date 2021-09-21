#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create:
**/
using namespace std;
typedef   long long ll;
typedef   unsigned long long ull;
#define ins(x)  insert(x);
#define endl  '\n'
#define  vi(x)  vector<int> x;
#define  pi   pair<int,int> x
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
#define mp make_pair
#define prec(n) fixed<<setprecision(n)
#define debug(n) cout<<(n)<<" "
#define debugn(n) cout<<(n)<<"\n";
// sortpair(v) sort(v.begin(), v.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) { return left.second < right.second; });
const int mod = (int) 1e9 + 7;
int a[1000000+100],par[1000000+100],res=1e9+7;
int root(int v){
    return par[v]? par[v]=root(par[v]): v;
}
void Megre(int u,int v,int x){
    if((u=root(u)) == (v=root(v))){
        if(a[u] > x) a[u]=x;
        return;
    }
    par[u]=v;
    a[u]=max(a[u],x);
    a[v]=a[u];
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> vals(m);
    int x,y,val;
    for(int i=0;i<m;++i){
        cin>>x>>y>>val;
        vals[i]={val,x,y};
    }
    sort(all(vals));
    for(int i=0;i<m;++i){
        Megre(get<1>(vals[i]), get<2>(vals[i]), get<0>(vals[i]));
    }

    map<int,int> mp;
    for(int i=0;i<n;++i){
        x = root(i);
        ++mp[x];
    }
    if(sz(mp)>1){
        cout<<"IMPOSSIBLE";
        return;
    }
    res=0;
    for(int i=0;i<n;++i){
        res= max(a[i],res);
    }
    cout<<res<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    //cin>>T;
    T=1;
    while(T--) solve();
return 0;
}
