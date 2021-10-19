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
void sol(){
    vector<int> a(10,0);
    int maxx=0;
    for(int i=0;i<10;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    for(int i=1;i<10;i++){
        if(a[i]==0){
            cout<<i<<endl;
            return;
        }
    }
    int d=1;
    while(d<=maxx){
        if(a[0]==d-1){
            string s="1";
            for(int i=0;i<=a[0];i++){
                s+='0';
            }
            cout<<s<<endl;
            return;
        }
        for(int i=1;i<10;i++)
        {
            if(a[i]==d){
                string s;
                for(int j=0;j<=a[i];j++){
                    s+=('0'+i);
                }
                cout<<s<<endl;
                return;
            }
        }
        d++;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        sol();
    }
}
