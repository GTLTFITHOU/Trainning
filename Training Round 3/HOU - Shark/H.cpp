#include<bits/stdc++.h>
using namespace std;

#define forn(n) for(int i=0; i<n; ++i)
#define foreach(x) for(auto a: x)
#define pr(x) cout << x
#define key(x) x->first
#define val(x) x->second

int64_t t;

void sov(){
    int a[10];
    for(int i=0; i<=9; ++i)
        cin >> a[i];

    if(a[1] == 0){
        cout << 1;
        return;
    }

    int minCan = a[1];
    for(int i=2; i<=9; ++i)
        if(a[i] < minCan)
            minCan = a[i];

    if(minCan > a[0]){
        cout << 1;
        for(int i=0; i<=a[0]; ++i)
            cout << 0;
    }
    else{
        for(int i=1; i<10; ++i){
            if(a[i] == minCan){
                for(int j=0; j<=a[i]; ++j)
                    cout << i;
                return;
            }
        }
    }
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
