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

int nck[3010][3010];

void init_nck(){
	for(int i = 0 ;i < 3010;i++){
		nck[i][0] = 1;
		for(int j = 1;j <= i;j++){
			nck[i][j] = nck[i - 1][j] + nck[i - 1][j - 1];
			if(nck[i][j] >= mod)
				nck[i][j] -= mod;
		}
	}
}

int add(int a, int b) {
	if (a + b >= mod) return a + b - mod;
	return a + b;
}

int sub(int a, int b) {
	if (a - b < 0) return a - b + mod;
	return a - b;
}

int mul(int a, int b) {
	return (1ll * a * b) % mod;
}

int binpow(int a, int b) {
	if (b <= 0) return 1;
	if (b % 2) return mul(a, binpow(a, b - 1));
	int m = binpow(a, b / 2);
	return mul(m, m);
}


int rev(int a) {
	return binpow(a, mod - 2);
	// return a^-1
}

// (a^b)%mod
inline int modpow(int a, int b, int m = mod) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return ret;
}

ll tg[4];

void mp2(ll x[],ll y[],ll z[])
{
	tg[0]=(x[0]*y[0]+x[1]*y[2])%mod;
	tg[1]=(x[0]*y[1]+x[1]*y[3])%mod;
	tg[2]=(x[2]*y[0]+x[3]*y[2])%mod;
	tg[3]=(x[2]*y[1]+x[3]*y[3])%mod;
	z[0]=tg[0];z[1]=tg[1];z[2]=tg[2];z[3]=tg[3];
}

ll fibonacci(ll n){
	ll t[4]={0,1,1,1},r[4]={0,1,1,1};
	tg[0] = tg[1] = tg[2] = tg[3] = 0;
	while(n)
	{
		if(n&1) mp2(r,t,r);
		mp2(t,t,t);
		n>>=1;
	}
	return r[2]%mod;
}

void solution()
{
	int n,m;
	re(n,m);
	vector<int> res(n+1,0),kqx(n+1,0), kqn(n+1,0);
	map<int,int> mpx,mpn;
	for(int i=1;i<=n;++i){
		res[i]=i;
		kqx[i]=i;
		kqn[i]=i;
		mpx[i]=i;
		mpn[i]=i;
	}
	for(int i=0;i<m;++i){
		int x,y;
		cin >> x;
		int vtb = mpx[x];
		int vte;
		if(vtb==1)continue;
		else vte = vtb-1;
		y = res[vte];
		mpn[y] = vte;
 		swap(res[vtb],res[vte]);
		mpx[x] = vte;
		mpx[y] = vtb;

		kqx[x]=max({kqx[x],vtb,vte});
		kqn[x]=min({kqn[x],vtb,vte});
		kqx[y]=max({kqx[y],vtb,vte});
		kqn[y]=min({kqn[y],vtb,vte});
	}
	for(int i=1;i<=n;++i){
		cout << kqn[i] << ' ' << kqx[i] << '\n';
	}
}

int main()
{
	setIO();
	srand(time(NULL));
	int t;
	t = 1;
	while(t--)
		solution();
	return 0;
}




