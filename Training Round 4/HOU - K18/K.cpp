#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

#define mx12 array<array<int,2>,1>
#define mx22 array<array<int,2>,2>

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

mx22 base {array<int, 2>{1, 0}, array<int, 2>{0, 1}};
mx22 baseA {array<int, 2>{1, 0}, array<int, 2>{1, 1}};
mx22 baseB {array<int, 2>{1, 1}, array<int, 2>{0, 1}};

mx22 mul(mx22 a, mx22 b) {
	auto ans = mx22();
	for (int rw_a = 0 ; rw_a < 2; rw_a++) {
		for (int col_b = 0 ; col_b < 2 ; col_b++) {
			ll tmp = 0;
			for (int i = 0 ; i < 2 ; i++) {
				tmp = (tmp + 1LL * a[rw_a][i] * b[i][col_b] ) % mod;
			}
			ans[rw_a][col_b] = tmp;
		}
	}
	return ans;
}

mx12 mul_ans(mx12 a, mx22 b) {
	auto ans = mx12();
	for (int rw_a = 0 ; rw_a < 1; rw_a++) {
		for (int col_b = 0 ; col_b < 2 ; col_b++) {
			ll tmp = 0;
			for (int i = 0 ; i < 2 ; i++) {
				tmp = (tmp + 1LL * a[rw_a][i] * b[i][col_b] ) % mod;
			}
			ans[rw_a][col_b] = tmp;
		}
	}
	return ans;
}

void showMX(mx22 x) {
	cout << x[0][0] << " " << x[0][1] << endl;
	cout << x[1][0] << " " << x[1][1] << endl;
	cout << endl;
}


mx22 node[maxn * 4];
int remUpd[maxn * 4];
int n, q;
string s;

void build(int id, int l, int r) {
	if (l == r) {
		node[id] = s[l] == 'A' ? baseA : baseB;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	node[id] = mul(node[id * 2], node[id * 2 + 1]);
}


mx22 updMX(mx22 inMx) {
	mx22 outMx;
	outMx[0][0] = inMx[1][1];
	outMx[1][0] = inMx[0][1];
	outMx[0][1] = inMx[1][0];
	outMx[1][1] = inMx[0][0];
	return outMx;
}

void downNode(int id) {

	int curRem = remUpd[id];
	remUpd[id * 2] = remUpd[id * 2] + curRem;
	if (curRem & 1) {
		node[id * 2] = updMX(node[id * 2]);
	}

	remUpd[id * 2+1] = remUpd[id * 2 + 1] + curRem;
	if (curRem & 1) {
		node[id * 2 + 1] = updMX(node[id * 2 + 1]);
	}

	remUpd[id] = 0;

}


void upd(int id, int l, int r, int u, int v) {
	if (r < u || v < l) {
		return ;
	}
	if (u <= l && r <= v) {
		remUpd[id] ++;
		node[id] = updMX(node[id]);
		return;
	}
	downNode(id);
	int mid = (l + r) / 2;
	upd(id * 2, l, mid, u, v);
	upd(id * 2 + 1, mid + 1, r, u, v);
	node[id] = mul(node[id * 2], node[id * 2 + 1]);
}

mx22 query(int id, int l, int r, int u, int v) {
	if (r < u || v < l) {
		return base;
	}
	if (u <= l && r <= v) {
		return node[id];
	}
	downNode(id);
	int mid = (l + r) / 2;
	mx22 lp = query(id * 2, l, mid, u, v);
	mx22 rp = query(id * 2 + 1, mid + 1, r, u, v);
	return mul(lp, rp);
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	cin >> s;
	s = " " + s;

	build(1, 1, n);

	while (q--) {
		int type, l, r, a, b;
		cin >> type >> l >> r;
		if (type == 1) {
			upd(1, 1, n, l, r);
		} else {
			cin >> a >> b;
			auto x = query(1, 1, n, l, r);
			auto inp = mx12{array<int, 2>{a, b}};
			auto ans = mul_ans(inp, x);
			cout << ans[0][0] << " " << ans[0][1] << endl;
		}
	}


}