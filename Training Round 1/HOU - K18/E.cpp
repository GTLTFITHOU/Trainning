#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

const int maxn = 1e6 + 5;

vector<pair<int,int>>adj[maxn];

int cnt = 0;
int pass[maxn];

void dfs(int u){
    if(pass[u]) return;
    pass[u] = 1;
    cnt++;
    for(auto ed : adj[u]){
        int v = ed.fir;
        int d = ed.sed;
        dfs(v);
    }

}

struct ed{
    ed(int _u, int _v, int _d){
        this->u = _u;this->v = _v;this->d = _d;
    }
    ed(){}
    int u,v,d;
};
struct DSU{
    int n;
    vector<int> p;
    vector<int> sz;
 
    DSU(int n){
        p = vector<int>(n);
        sz = vector<int>(n);
        this->n = n;
        for(int i = 0 ; i < n ; i++){
            p[i] = i;
            sz[i] = 1;
        }
    }
    int findRoot(int id){
        if (p[id] == id) return id;
        return p[id] = findRoot( p[id] );
    }
    int mergeNode(int a,int b){
        // return root after merge
        int ra = findRoot(a);
        int rb = findRoot(b);
        if ( ra!=rb ){
            if (sz[ra] < sz[rb]) swap(ra,rb);
            sz[ra] += sz[rb];
            p[rb] = ra;
        }
        return ra;
    }
};
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<ed> eds;
    for(int i = 0 ; i < m ; i++){
        int u,v,d;
        cin>>u>>v>>d;
        adj[u].epb(v,d);
        adj[v].epb(u,d);
        eds.epb(u,v,d);
    }
    dfs(0);
    // show(cnt);
    if(cnt!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        DSU dsu(n);
        sort(all(eds),[](ed a, ed b){ return a.d < b.d; });
        int ans = 0;
        for(auto ed : eds){
            int u = ed.u;
            int v = ed.v;
            int d = ed.d;
            if( dsu.findRoot(u) != dsu.findRoot(v) ){
                ans = max(ans,d);
                dsu.mergeNode(u,v);
            }
        }
        cout<<ans<<endl;
    }
}