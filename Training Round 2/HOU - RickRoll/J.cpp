// not ac yet
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define prec(n) fixed<<setprecision(n)
#define debug(n) cout<<(n)<<" "
#define debugn(n) cout<<(n)<<endl;
#define ntest 0
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sum(a) ( accumulate ((a).begin(), (a).end(), 0ll))
#define sz(x) ((int)x.size())
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a)/__gcd(a,b)*(b)
#define endl '\n'
#define TIME cerr<<(clock() * 1.0 / CLOCKS_PER_SEC)
using namespace std;
using namespace __gnu_pbds;
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) {
    vec.assign(len, val);
}
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &v : vec) is >> v;
    return is;
}
template <typename T> istream &operator>>(istream &is, vector<pair<T, T>> &vec) {
    for (auto &v : vec) is >> v.fi >> v.se ;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto v : vec) os << v << ' ';
    return os;
}
template <typename T> ostream &operator<<(ostream &os, const vector<pair<T, T>> &vec) {
    for (auto v : vec) os << v.fi << " " << v.se << endl;
    return os;
}
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef vector<pii> vii;
const int mod = (int) 1e9 + 7;
const int inf = (int) 1e9 + 7;
const ll infll = (ll) 1e18 + 7;
//typedef arr<int,3> arr;
struct dji {
    int cur = -1;//dinh? vua tham
    set<int> vis;//dinh? da tham
    int pick;//so point da nhat
    int d;//quang duong da di
};
//djikstra bai nay chac la e dung djikstra :v. do lan dau dung` nen e cung k chac
void solve() {
    int n, m;
    cin >> n;
    vi a(n);
    cin >> a;
    vector<vi> ma(n + 1, vi(n + 1, 0));// ma tran ke luu nhung duong co the di
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ma[x][y] = z;
        ma[y][x] = z;
    }

    vector<dji>  cur, res;
    for(int i = 1; i <= n; i++) {
        if(ma[1][i]) {
            dji dji;
            dji.cur = i;
            dji.pick = a[i - 1] + a[0];
            dji.d = ma[1][i];
            dji.vis.ins(1);
            dji.vis.ins(i);
            cur.pb(dji);
            if(i == n) res.pb(dji);
        }
    }

    while(cur.size()) {
        vector<dji> b;
        map<int, int> mp;
        for(int j = 0; j < cur.size(); j++) {
            for(int i = 1; i <= n; i++) {
                dji dji = cur[j];
                if(ma[dji.cur][i] && dji.vis.find(i) == dji.vis.end()) {
                    dji.pick += a[i - 1];
                    dji.d += ma[dji.cur][i];
                    dji.cur = i;
                    dji.vis.ins(i);
                    if(i == n) res.pb(dji);
                    else b.pb(dji);
                }
            }
        }
        cur.clear();
        for(auto i : b) {
            if(mp.count(i.cur) == 0) {
                mp[i.cur] = i.d;
            } else {
                mp[i.cur] = min(i.d, mp[i.cur]);
            }
        }
        for(auto i : b) {
            if(i.d == mp[i.cur])
                cur.pb(i);
        }
    }

    int mx = 0, mn = inf;
    for(auto i : res) {
        if(i.d < mn) {
            mn = i.d;
            mx = i.pick;

        } else if(mn == i.d) {
            mx = max(mx, i.pick);
        }
    }

    if(mn == inf) {
        cout << "impossible";
    }
    else
        cout << mn << " " << mx << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Tc;
    if(ntest) {
        cin >> Tc;
        while(Tc--)
            solve();
    } else {
        solve();
    }
}

/*

*/
