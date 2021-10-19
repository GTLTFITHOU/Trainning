#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 0;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll n, q;
ll o_row[MAX_N], o_col[MAX_N];
void pdthang2000() {
    cin >> n >> q;
    vector<ll> r(n + 1), c(n + 1);
    for (ll i = 1; i <= n; ++i) {
        cin >> r[i];
        o_row[i] = o_row[i - 1] + (r[i] & 1);
        // cout << o_row[i] << ' ';
    }
    // UWU;
    for (ll i = 1; i <= n; ++i) {
        cin >> c[i];
        o_col[i] = o_col[i - 1] + (c[i] & 1);
        // cout << o_col[i] << ' ';
    }
    // UWU;

    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll cnt_row = o_row[max(a, c)] - o_row[min(a, c) - 1];
        ll cnt_col = o_col[max(b, d)] - o_col[min(b, d) - 1];
        // see(cnt_row);seen(cnt_col);
        if (r[min(a, c)] & 1) { // Odd
            // cout << "Odd\n";
        // number of odd equal to lenght or not
            if (cnt_row == max(a, c) - min(a, c) + 1 &&
                cnt_col == max(b, d) - min(b, d) + 1) {
                    cout << "YES";
            } else {
                cout << "NO";
            }
        } else { // Even
            // cout << "Even\n";
            if (cnt_row == 0 && cnt_col == 0) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
        UWU;
    }
    
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (MULTI_TESTS) {
        ll Q;
        cin >> Q;
        while (Q--) {
            pdthang2000();
            endl;
        }
    } else {
        pdthang2000();
    }
}
/*
--- use for float, double a.k.a real number ---
cout.precision(18);
cout << fixed;
*/

/*
--- use for unordered_map which make it run faster --- 
ex: 
unordered_map<ll, ll, custom_hash> mp;
mp.reserve(2 ^ n);
mp.max_load_factor(0.1);
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
*/

/*
--- ordered_set: set with advanced func ---

order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).

declare : ordered_set name; 
you have to define the datatype in #define

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag,tree_order_statistics_node_update>
*/