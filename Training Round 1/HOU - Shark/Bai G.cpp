#include<bits/stdc++.h>
using namespace std;

#define forn(n) for(int i=0; i<n; ++i)
#define foreach(x) for(auto a: x)
#define pr(x) cout << x
#define key(x) x->first
#define val(x) x->second

int64_t t;

void sov(){
    int solon, dong1, dong5, dong10;
    cin >> solon >> dong1 >> dong5 >> dong10;

    if(dong10 > solon){
        cout << solon;
        return;
    }
    int ans = 0;
    solon -= dong10;
    ans += dong10;

    if(dong5/2 > solon){
        ans += solon*2;
        cout << ans;
        return;
    }

    int sodong5them = dong10;
    if(dong5 <= solon){
        ans += dong5*4;
        solon -= dong5;
        if(sodong5them <= solon){
            ans += sodong5them*7;
            solon -= sodong5them;
        }
        else{
            ans += solon*7;
            solon = 0;
        }
        cout << ans + solon*8;
        return;
    }

    ans += solon*4;
    dong5 -= solon;
    if(dong5 <= solon){
        ans -= dong5*2;
    }
    else{
        ans -= solon*2;
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        sov();
        pr(endl);
    }
}
//greater <int>
