#include <bits/stdc++.h>
using namespace std;
#define NAME "easy"
ifstream fi (NAME".inp");
ofstream fo (NAME".out");
#define ff first
#define ss second
#define yes "YES"
#define no "NO"
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fora(i, a, b) for(int i = (a); i <= (b); i++)
#define forb(i, a, b) for(int i = (a); i >= (b); i--)
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int l,d,n;
    cin>>l>>d>>n;
    vector<int> a;
    a.pb(l-6);
    a.pb(6);
    int res;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.pb(x);
    }
    sort(all(a));
    //cout<<a<<endl;
    res=a.size();
    for(int i=0;i<a.size()-1;i++){
        res+=(a[i+1]-a[i])/d-1;
    }
    cout<<res-n;
}
