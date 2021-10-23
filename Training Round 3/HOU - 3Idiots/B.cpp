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
#define TC 0
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;

/**
    có n nhân viên  và k đội
    các đội đánh số từ 1 đến k
*/
ll check( multiset<int> st,ll m){
    ll res=0;
    while(!st.empty()){
        auto it = st.begin();
        if(*it>m) return 0;

        auto up = (st.upper_bound((m - *it) ));

        //cout<<*it<<" "<<*up<<" "<<m<<endl;
        if(up==st.end()) --up;
        while(up!=st.begin() && *up>(m-*it) ){
            --up;
        }
       // cout<<*it<<" - "<<*up<<endl;
        if( it!=up && *it + *up <=m){
            ++res;
            st.erase(it);
            st.erase(up);
        }else if(*it <=m){
            ++res;
            st.erase(it);
        }
    }
    return res;
}

void solve()
{
    int n,k,x;
    cin>>n>>k;
    vector<int> a(k+1,0);
    multiset<int> st;
    for(int i=0;i<n;++i){
        cin>>x;
        ++a[x];
    }
    ll sum=0;
    for(int i=1;i<=k;++i){
        st.insert(a[i]);
    }
    sort(all(a));

    ll ans=2e18,res=0,i=a[k];
    sum=a[k]+ a[k/2];
    for(;i<=sum;++i){
        if( (res= check(st,i)) ){
            ans=min(ans,res*i);
        }
    }
    cout<<ans<<endl;
}
int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    if(TC){
        int T;
        cin>>T;
        while(T--) solve();
    }else{
        solve();
    }
return 0;
}
