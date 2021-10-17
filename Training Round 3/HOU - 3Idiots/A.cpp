#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 9/10/2021
* @contest: CLB
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
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define TC 0
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;
 
 
void solve()
{
    int n,m,x;
    cin>>n>>m;
    vector<int> ra(n+1,0), can(n+1,0);
    map<int,int> mp;
    vector< vector<int>  > res(n+1);
 
    for(int i=1;i<=n;++i)
    {
        res[i].pb(i);
        ra[i]=i;  // rank i =  bài thứ  ra[i]
        mp[i]=i;  // bài thứ i đang tại rank i
    }
 
    int raX, raY; // rank X , rank Y
    for(int i=1;i<=m;++i){
        cin>>x; // bai x tang them i luot
         can[x] += i;
         raX= mp[x];// rank X
 
        if(raX == 1) continue;
 
            raY = raX-1; // rank của Y
            int y = ra[raY];
            //if(can[x] > can[y]){
                mp[x]=raY;
                mp[y]=raX;
                ra[raX]=y;
                ra[raY]=x;
                res[x].pb(raY);
                res[y].pb(raX);
                /*cout<<x<< " "<<raY<<endl;
                cout<<y<<" "<<raX<<endl;
                cout<<endl;*/
           // }
 
    }
    for(int i=1;i<=n;++i){
       sort(all(res[i]));
        cout<<res[i][0]<<" "<<res[i][ sz(res[i])-1]<<endl;
    }
 
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    if(TC){
        int T;
        cin>>T;
        while(T--) solve();
    }else{
        solve();
    }
return 0;
}