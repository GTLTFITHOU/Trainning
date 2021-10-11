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

// k hàng  cùng số lượng lính
// các quân lính cùng 1 hàng không được chênh nhau quá 1

ll n,k;
ll c[30000+100];
bool check(ll m){
    ull res=0,cur=0;
    for(int i=0;i<n;++i){
        if(c[i] + cur >= m){
            res+= (c[i]+cur)/m;
            cur=(c[i]+cur)%m;// dư ở hiện tại
        }else if( i!= (n-1)  && c[i] + c[i+1]>=m){
            res+= (c[i]+c[i+1])/m;
            cur = (c[i]+c[i+1])%m;
            ++i;
        }else{
            cur=c[i];
        }
    }
    return res>=k;
}

void solve()
{
    cin>>n>>k;// chiều cao của binh sĩ, và sô hàng  của binh sỹ
    ull sum=0;
    for(int i=0;i<n;++i){
        cin>>c[i];
        sum+=c[i];
    }
    ull l=1,m, r=sum,res=0;
    while(l<=r){
        m=(r+l)/2;
        if(check(m)){
            res=m*k;
            l=m+1;
        }else r=m-1;
    }
    cout<<res<<endl;
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
