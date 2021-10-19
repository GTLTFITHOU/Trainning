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

struct DSU {
	//vector<int> p;

	map<int, int> p;
	map<int, int> sz;

	DSU() {
	}

	int findRoot(int id) {

		if (p.find(id) == p.end()) {
			p[id] = id;
			return id;
		}

		if (p[id] == id) return id;
		return p[id] = findRoot( p[id] );
	}

	int getSz(int id) {
		if (sz.find(id) == sz.end()) {
			sz[id] = 1;
		}
		return sz[id];
	}

	int mergeNode(int a, int b) {
		// return root after merge
		int ra = findRoot(a);
		int rb = findRoot(b);
		if ( ra != rb ) {
			if (getSz(ra) < getSz(rb)) swap(ra, rb);
			sz[ra] += sz[rb];
			p[rb] = ra;
		}
		return ra;
	}
};

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector< pair<int, int> > ed(n);
		DSU dsu;

		vector<int> make_cycle;
		
		map<int,int> dgr;

		for (int i = 0 ; i < n ; i++) {
			int u, v;
			cin >> u >> v;
			ed[i] = {u, v};

			dgr[u]++;
			dgr[v]++;

			if (dsu.findRoot(u) == dsu.findRoot(v)) {
				make_cycle.epb(i);
			}
			dsu.mergeNode(u, v);
		}

		map<int, int > GCYS;
		for (auto e : make_cycle) {
			int r = dsu.findRoot(ed[e].fir) ;
			GCYS[r] = e;
		}

		map< int, pair<int,int> > ans;
		set<int> sr;
		for(int i = 0 ; i < n ; i++){
			int u = ed[i].fir;
			int v = ed[i].sed;
			int r = dsu.findRoot(u);
			sr.insert(r);
			if(dgr[u] == 1){
				ans[r] = {i,u};
				continue;
			}
			if(dgr[v] == 1){
				ans[r] = {i,v};
				continue;
			}
		}

		vector<int> vr(sr.begin(),sr.end());

		cout<<sz(vr)-1<<endl;

		function< pair<int,int>(int) > getP = [&](int r)->pair<int,int>{
			if(ans.find(r) == ans.end()){
				int idx = GCYS[r];
				return {idx,ed[idx].sed};
			}else{
				return ans[r];
			}
		};

		for(int i = 0 ; i < sz(vr) - 1 ; i++){
			int r = vr[i];
			int nr = vr[i+1];
			auto pr = getP(r);
			auto pnr = getP(nr);
			int nxU = ed[ pnr.fir ].fir == pnr.sed ?  ed[ pnr.fir ].sed : ed[ pnr.fir ].fir;

			cout << pr.fir + 1 << " " << pr.sed << " " << nxU<<endl;
		}

	}
}
