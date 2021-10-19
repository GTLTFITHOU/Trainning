#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 9/10/2021
* @contest: CLB
**/
using namespace std;
typedef   long long ll;
typedef   pair<int,int> ii;
typedef   vector<ii> vii;
typedef   unsigned long long ull;
#define ins(x)  insert(x);
#define endl  '\n'
#define tup tuple<int,int,int>
#define pb push_back
#define rsz resize
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define TC 1
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;


int b[10];
void solve()
{
     vector<pair<int,int>> a(10);
     for(int i=0;i<10;++i){
        cin>>a[i].f; // a.f là số  lượng
         a[i].s=i;// a.s là vị trí
         b[i] = a[i].f;
     }
     sort(a.begin(), a.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right)
     { return left.f == right.f ? ( left.s < right.s ):( left.f < right.f);});

    if(a[0].s==0){
        if(a[1].f == 0){
            cout<<a[1].s<<endl;
            return;
        }else if(a[1].f == a[0].f){
            string res="";
            char x= a[1].s + '0';
            for(int i=0;i<= b[ a[1].s ]; ++i ){
                res.pb(x);
            }
            cout<<res<<endl;
            return;
        }
        else {
            string res="1";
            for(int i=0;i<=b[0];++i){
                res.pb('0');
            }
            cout<<res<<endl;
            return;
        }

    }else{
        string res="";
        char x= a[0].s + '0';
        for(int i=0;i<= b[ a[0].s]; ++i ){
            res.pb(x);
        }
        cout<<res<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    if(TC){
        int T;
        cin>>T;
        while(T--) solve();
    }else{
        solve();
    }
return 0;
}
