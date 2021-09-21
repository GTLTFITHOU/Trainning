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
set<int> a;
void build(int n){
    int N=sqrt(n);
    for(int i=2;i<=N;++i){
        if(n%i==0){
            a.insert(n/i);
            a.insert(i);
        }
    }
}
void solve()
{
    string s;
    cin>>s;
    a.insert(1);
    build(sz(s));
    for(auto &x: a){
            map<string,int> mp;
            string str;
        for(int i=0;i+x<=sz(s);i+=x){
            str = s.substr(i,x);
            sort(all(str));
            ++mp[str];
            if(sz(mp) >1) break;
        }
        if(sz(mp) == 1){
            cout<<(s.substr(0,x));
            return;
        }
    }
    cout<<-1;
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
