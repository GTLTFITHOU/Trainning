#include<bits/stdc++.h>
using namespace std;

#define forn(n) for(int i=0; i<n; ++i)
#define foreach(x) for(auto a: x)
#define pr(x) cout << x
#define key(x) x->first
#define val(x) x->second

int64_t t;

void sov(){
    int a,b,c;
    cin >> a >> b >> c;

    int sochuyenmax = b;
    if(a > c){
        sochuyenmax = min(a - c,b);
        c += b;
        b = 0;
        if(c > a){
            b = c-a;
            c = a;
        }
    }
    else{
        sochuyenmax = min(c - a,b);
        a += b;
        b = 0;
        if(a > c){
            b = a-c;
            a = c;
        }
    }

    if(b == a){
        cout << b;
        return;
    }
    if(a == c){
        if(b > a){
            int lambang = (b - a)/3 + ((b - a)%3 != 0);
            cout << a + lambang;
        }
        else{
            int lambangmax = sochuyenmax;
            int lambang = (a - b);
            if(lambangmax < lambang)
                lambang = lambangmax;


            a -= lambang;
            b += lambang*2;
            if(b == a){
                cout << b;
            }
            else if(b > a){
                lambang = (b - a)/3 + ((b - a)%3 != 0);
                cout << a + lambang;
            }
            else{
                cout << a;
            }
        }
        return;
    }

    // a != c
    if(a < c){
        int td = a;
        a = c;
        c = td;
    }

    int demoa = a;
    a = demoa/2 + (demoa%2 != 0);
    if(a >= c){
        cout << a;
        return;
    }
    if(demoa % 2 != 0){
        c--;
        sochuyenmax--;
    }
    int lambang = c - a - sochuyenmax;
    if(sochuyenmax <= lambang*2){
        cout << c - sochuyenmax;
        return;
    }

    lambang = (c - a)/3 + ((c - a)%3 != 0);
    cout << a + lambang;
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
