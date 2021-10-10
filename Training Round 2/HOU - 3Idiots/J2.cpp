#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 6/10/2021
* @contest: practice
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
//vector<vector<int>> a(101,vector<int>(100));

int n;
vector<vector<int>> roads(110);
map<pair<int,int>,int> mp;
vector<int> a(110), can(110,0),res(110,99999);
//bool used[110];

void dfs(int x,int V, int M){
    int v,m;
    for(int i=0;i<sz(roads[x]);++i){
        v=V +mp[{x,roads[x][i]}];
        m=M+ a[roads[x][i]];
        if(v<res[roads[x][i]]){
            res[roads[x][i]]=v;
            can[roads[x][i]]=m;
            dfs(roads[x][i],res[roads[x][i]],can[roads[x][i]]);
        }else if(v==res[roads[x][i]] && m > can[roads[x][i]]){
            can[roads[x][i]]=m;
            dfs(roads[x][i],res[roads[x][i]],can[roads[x][i]]);
        }
    }
}
void solve()
{
    cin>>n;
    int x,y,d,m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    cin>>m;

    for(int i=0;i<m;++i){
        cin>>x>>y>>d;
        mp[{x,y}]=d;
        mp[{y,x}]=d;
        roads[x].pb(y);
        roads[y].pb(x);
    }
    int V=0,M=a[1];
    dfs(1,V,M);
    if(res[n]==99999){
        cout<<"impossible";
        return;
    }
    cout<<res[n]<<" "<<can[n];


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
