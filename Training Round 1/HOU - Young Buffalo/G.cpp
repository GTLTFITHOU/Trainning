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

const int B = -1;
int mem[200][200][55];
int total;

int MIN(int c, int n5, int n10) {
    if (c == 0) return 0;
    int n1 = total - n5 * 5 - n10 * 10;
    n1 = min(c * 8, n1);
    n5 = min(c * 2, n5);
    n10 = min(c, n10);
    if (mem[c][n5][n10] != B) return mem[c][n5][n10];
    int mn = c * 8;
    if (n10 > 0)
      mn = min(mn, 1 + MIN(c - 1, n5, n10 - 1));
    if (n5 >= 1 && n1 >= 3)
      mn = min(mn, 4 + MIN(c - 1, n5 - 1, n10));
    if (n5 >= 2)
      mn = min(mn, 2 + MIN(c - 1, n5 - 2, n10));
    if (n1 >= 8)
      mn = min(mn, 8 + MIN(c - 1, n5, n10));
    if (n10 >= 1 && n1 >= 3)
      mn = min(mn, 4 + MIN(c - 1, n5 + 1, n10 - 1));
    mem[c][n5][n10] = mn;
	return mn;
}

int main()
{
	setIO();
	srand(time(NULL));
	int t,c,n1,n5,n10;
	re(t);
    while (t--) {
      for(int i=0;i<200;++i)
		  for(int j=0;j<200;++j)
			  for(int k=0;k<55;++k)
				  mem[i][j][k]=B;
	  re(c); re(n1); re(n5); re(n10);
      total = n1 + n5 * 5 + n10 * 10;
      cout << MIN(c, n5, n10) << '\n';
    }
	return 0;
}















