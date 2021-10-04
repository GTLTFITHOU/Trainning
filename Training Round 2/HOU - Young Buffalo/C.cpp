#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz(x) x.size()
#define pb(x) push_back(x)
#define all(a) a.begin(),a.end()
#define setp(x) fixed << setprecision(x)

using namespace std;

typedef complex<long double> cd;
namespace input {
    template<class T> void re(complex<T>& x);
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    void re(long double& x) { string t; re(t); x = stold(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.ff,p.ss); }
    template<class T> void re(vector<T>& a) {
        for(auto &i:a)re(i);
    }
    template<class T, size_t SZ> void re(array<T,SZ>& a) {
        for(int i=0;i<SZ;++i) re(a[i]);
    }
}

using namespace input;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

namespace io
{
    void setIn(string s) { ifstream cin (s);}
    void setOut(string s) {ofstream cout (s);}
    void setIO(string s = "")
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin.exceptions(cin.failbit);
        if (sz(s)) setIn(s+".inp"), setOut(s+".out");
    }
}
using namespace io;

constexpr int mod = 1e9+7;



int main()
{
    setIO();
    srand(time(NULL));
    int a,b,c,l;
    cin >> a >> b >> c >> l;
    vector<vector<int>> ans;
    for(int i=0;i<=l/a+1;++i){
        for(int j=0;j<=l/b+1;++j){
            int x = i*a + j*b;
            int v = l-x;
            if(v>=0){
                if(v%c==0){
                    ans.push_back({i,j,v/c});
                }
            }
        }
    }
    sort(all(ans));
    if(ans.size()){
        for(auto i:ans){
            for(auto j:i) cout << j<<' ';
            cout<<'\n';
        }
    }
    else{
        cout << "impossible\n";
    }
    return 0;
}