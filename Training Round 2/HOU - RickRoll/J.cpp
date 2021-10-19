#include<bits/stdc++.h>
#define pb push_back
#define ins insert
#define ntest 0

using namespace std;

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

struct vertex {
    int cur = -1;//dinh? vua tham
    int pick;//so point da nhat
    int d;//quang duong da di
};
//bai nay chac la e dung djikstra :v. do lan dau dung` nen e cung k chac
void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> ma(n + 1, vector<int>(n + 1, 0));// ma tran ke luu nhung duong co the di
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ma[x][y] = z;
        ma[y][x] = z;
    }

    vector<vertex>  cur, shortest(n+1);
    auto chk = [&] (vertex dj) {
        vertex tmp = shortest[dj.cur];
        if(tmp.cur == -1) {
            shortest[dj.cur] = dj;
            return 1;
        } else {
            if(dj.d < tmp.d) {
                shortest[dj.cur] = dj;
                return 1;
            } else if(dj.d == tmp.d) {
                if(dj.pick > tmp.pick) {
                    shortest[dj.cur] = dj;
                    return 1;
                }
            }
        }
        return 0;
    };

    for(int i = 1; i <= n; i++) {
        if(ma[1][i]) {
            vertex vertex;
            vertex.cur = i;
            vertex.pick = a[i - 1] + a[0];
            vertex.d = ma[1][i];
            cur.pb(vertex);
            chk(vertex);
        }
    }

    while(cur.size()) {
        set<int> vis;
        for(int j = 0; j < cur.size(); j++) {
            for(int i = 1; i <= n; i++) {
                vertex vertex = cur[j];
                if(ma[vertex.cur][i] ) {
                    vertex.pick += a[i - 1];
                    vertex.d += ma[vertex.cur][i];
                    vertex.cur = i;
                    if(chk(vertex)) vis.ins(i);
                }
            }
        }
        cur.clear();
        for(auto i : vis) {
            cur.pb(shortest[i]);
        }
    }

    if(shortest[n].cur != -1) {
        cout << shortest[n].d << " " << shortest[n].pick << endl;
    }
    else {
        cout << "impossible";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

}

/*

*/
