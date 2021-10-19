#include<bits/stdc++.h>
using namespace std;

#define forn(n) for(int i=0; i<n; ++i)
#define foreach(x) for(auto a: x)
#define pr(x) cout << x
#define key(x) x->first
#define val(x) x->second
#define res(a,b,c) cout << a << " " << b << " " << c << endl

int64_t t;

void sov(){
    int b,d,c,l;
    cin >> b >> d >> c >> l;

    if(b == 0 && d == 0 && c == 0){
        cout << "impossible";
        return;
    }

    int chanb = 0;
    bool check = 1;
    while(chanb*b <= l){
        int chand = 0;
        while(chand*d + chanb*b <= l){
            int chanc = l - chanb*b - chand*d;
            if(chanc%c == 0){
                res(chanb, chand, chanc/c);
                check = 0;
            }
            chand++;
        }
        chanb++;
    }

    if(check)
        cout << "impossible";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        sov();

}
//greater <int>
