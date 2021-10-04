#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 1;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll max_3(ll a, ll b, ll c) {
    return max(a, max(b, c));
}
ll min_3(ll a, ll b, ll c) {
    return min(a, min(b, c));
} 
ll cal_align(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
    return (a1 + a2 + a3) * max_3(b1, b2, b3);
}
ll cal_2(ll h1, ll h2, ll wd, ll wu1, ll wu2, ll wid, ll hei) {
    ll width, height;
    // see(h1);seen(h2);see(wd);see(wu1);seen(wu2);see(wid);seen(hei);
    if (h1 == h2) {
        width = max(wd, wid);
        height = h1 + hei;
        // see(width);seen(height);
        return width * height;
    }
    width = wu1 + max(wid, wu2);
    height = max(h2 + hei, h1);
    // see(width);seen(height);
    return width * height;
}
ll cal_com(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
    ll ans = ULONG_LONG_MAX;
    /*
     _
    | | _
    | || |
    | || |
    */
    // h1, h2
    ll h1, h2, wd, wu1, wu2;
    h1 = max(a1, a2);
    h2 = min(a1, a2);
    wd = b1 + b2;
    wu1, wu2;
    if (h1 == a1) {
        wu1 = b1;
        wu2 = b2;
    } else {
        wu1 = b2;
        wu2 = b1;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a3, b3));
    // h2, h3
    h1 = max(a2, a3);
    h2 = min(a2, a3);
    wd = b2 + b3;
    wu1, wu2;
    if (h1 == a2) {
        wu1 = b2;
        wu2 = b3;
    } else {
        wu1 = b3;
        wu2 = b2;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a1, b1));
    // h1, h3
    h1 = max(a1, a3);
    h2 = min(a1, a3);
    wd = b1 + b3;
    wu1, wu2;
    if (h1 == a1) {
        wu1 = b1;
        wu2 = b3;
    } else {
        wu1 = b3;
        wu2 = b1;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a2, b2));
    return ans;
}
void pdthang2000() {
    ll a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    ll res = ULONG_LONG_MAX;
    res = min(res, cal_align(a1, b1, a2, b2, a3, b3));
    res = min(res, cal_align(a1, b1, a2, b2, b3, a3));
    res = min(res, cal_align(a1, b1, b2, a2, b3, a3));
    res = min(res, cal_align(a1, b1, b2, a2, a3, b3));
    res = min(res, cal_align(b1, a1, b2, a2, b3, a3));
    res = min(res, cal_align(b1, a1, b2, a2, a3, b3));
    res = min(res, cal_align(b1, a1, a2, b2, b3, a3));
    res = min(res, cal_align(b1, a1, a2, b2, a3, b3));
    // seen(res);
    //
    res = min(res, cal_com(a1, b1, a2, b2, a3, b3));
    res = min(res, cal_com(a1, b1, a2, b2, b3, a3));
    res = min(res, cal_com(a1, b1, b2, a2, b3, a3));
    res = min(res, cal_com(a1, b1, b2, a2, a3, b3));
    res = min(res, cal_com(b1, a1, b2, a2, b3, a3));
    res = min(res, cal_com(b1, a1, b2, a2, a3, b3));
    res = min(res, cal_com(b1, a1, a2, b2, b3, a3));
    res = min(res, cal_com(b1, a1, a2, b2, a3, b3));
    cout << res;
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