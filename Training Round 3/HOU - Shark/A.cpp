#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define ntest 0
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MOD = (int) 1e9 + 7;
int t;
int n, m;
int x[100000 + 100];
struct vt{
    int caonhat;
    int thapnhat;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    int a[m + 10];
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    map<int, vt> Map;
    map<int, int> vitri;
    for(int i = 1; i <= n; i++){
        Map[i].caonhat = i;
        Map[i].thapnhat = i;
        vitri[i] = i;
        x[i] = i;
    }
    for(int i = 0; i < m; i++){
        int vt = vitri[a[i]];
        //cout << vt << endl;
        //cout << vt << " " << a[i] << endl;
        if(vt != 1){
            Map[x[vt]].caonhat = min(Map[x[vt]].caonhat, vt - 1);
            Map[x[vt - 1]].thapnhat = max(Map[x[vt - 1]].thapnhat, vt);
            vitri[a[i]] = vt - 1;
            vitri[x[vt - 1]] = vt;
            swap(x[vt], x[vt - 1]);
            /*
            for(int i = 1; i <= n; i++){
                cout << x[i] << " ";
            }
            cout << endl;
            */
        }
    }
    for(int i = 1; i <= n; i++){
        cout << Map[i].caonhat << " " << Map[i].thapnhat << endl;
    }
}

