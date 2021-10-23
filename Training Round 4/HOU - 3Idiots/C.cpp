#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 17/10/2021
* @contest: Practice
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
const int Nmax= 100*1000+100;
int a[Nmax],b[Nmax],par1[Nmax],par2[Nmax];
int root1(int v){
    return par1[v]? par1[v]=root1(par1[v]) : v;
}
int root2(int v){
    return par2[v]? par2[v]=root2(par2[v]) : v;
}
void Merge1(int u, int v){
    u=root1(u), v= root1(v);
    if(u==v) return;
    if(u>v) swap(u,v);
    par1[v]=u;
}
void Merge2(int u, int v){
    u=root2(u), v= root2(v);
    if(u==v) return;
    if(u>v) swap(u,v);
    par2[v]=u;
}
 
void solve()
{
    int N,Q;
    cin>>N>>Q;
    for(int i=1;i<=N;++i){cin>>a[i];}
    for(int i=1;i<=N;++i){cin>>b[i];}
    for(int i=1;i<N;++i){
        if(a[i]%2 == a[i+1]%2){
            Merge1(i,i+1);
        }
        if(b[i]%2 == b[i+1]%2){
            Merge2(i,i+1);
        }
    }
    int ra,ca,rb,cb;
    while(Q--){
        cin>>ra>>ca>>rb>>cb;
        int A,B,C,D;
        A=root1(ra);
        B=root2(ca);
        C=root1(rb);
        D=root2(cb);
        if(A==C && B==D){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
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