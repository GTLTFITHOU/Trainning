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

const int MOD = 10000;
const string tg = "welcome to code jam";
const int tgl= 19;


int dp(int i, int j, const string& ss, vector<vector<int>>& mem) {
    if (ss.length() - i < tgl- j)
        return 0;

    if (mem[i][j] == -1) {
        const string substr = ss.substr(i);
        if (j == 18)
            mem[i][j] = count(substr.begin(),substr.end(),tg.back());
        else
            mem[i][j] = ((ss[i] == tg[j] ? dp(i + 1, j + 1, ss, mem) : 0) + dp(i + 1, j, ss, mem)) % MOD;
    }
    return mem[i][j];
}

string dmm(const string& ss) {
    vector<vector<int>> mem(ss.length(), vector<int>(19, -1));
    string cnt = to_string(dp(0, 0, ss, mem));
    return string(4 - cnt.length(), '0') + cnt;
}

int main() {

    int t;
    string ss;
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; ++i) {
        getline(cin, ss);
        cout << "Case #" << i << ": " <<dmm(ss) << '\n';
    }
    return 0;
}