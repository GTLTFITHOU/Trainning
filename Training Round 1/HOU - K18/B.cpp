#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

const int maxn = 1e5 + 5;

int cnt[maxn][26];
string s;
int n;

bool check(int l){
    // show(l);
    // show(n);
    int pre = -1;
    vector<int> tmp(26,0);

    for(int i = 0 ; i < n ; i += l){

        vector<int> cur(26,0);
        for(int j = 0 ; j < 26 ; j++){
            cur[j] = cnt[i+l-1][j] - ( i > 0 ? cnt[i-1][j] : 0 );
        }

        if(pre == -1){
            tmp = cur;
            pre = 1;
            continue;
        }

        for(int j = 0 ; j < 26 ; j++){
            if( cur[j] != tmp[j] ) return false;
        }

    }
    // show(pre);
    return true;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> s;
    n = len(s);
    if(s == string(n,s[0])){

        cout<<s[0]<<endl;
        return 0;

    }else{

        for(int i = 0 ; i < n ; i++){
            if(i > 0){
                for(int j = 0 ; j < 26 ; j++) 
                    cnt[i][j] = cnt[i-1][j];    
            }

            cnt[i][ s[i] - 'a' ] ++;
            
        }

        vector<int> ds;
        
        for(int i = 2 ; i <= n ;i++)
            if(n%i==0) ds.epb(n/i);

        // for(auto x : ds) cout<<x<<" ";
        // cout<<endl;

        for(int i = sz(ds)-1 ; i >= 0 ; i--){

                // show(ds[i]);
                if(check(ds[i])){
                    cout<<s.substr(0,ds[i]);
                    return 0;
                }

            
        }
    }

    cout<<-1<<endl;
    
}