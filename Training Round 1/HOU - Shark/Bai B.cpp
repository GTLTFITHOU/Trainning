#include<bits/stdc++.h>
using namespace std;

#define forn(n) for(int i=0; i<n; ++i)
#define foreach(x) for(auto i: x)
#define pr(x) cout << x
#define key(x) x->first
#define val(x) x->second

int64_t t;

void sov(){
    char s[100000 + 5];
    cin >> s;

    int lenS = strlen(s),a[100000 + 5], lenA = 0;
    for(int i=1; i<=lenS/2; ++i){
        if(lenS % i == 0){
            a[lenA++] = i;
        }
    }

    for(int i=0; i<lenA; ++i){
        bool check = 1;
        int len = a[i], charS[1000] = {0}, lenAns = 0, j;
        char ans[100000];
        for(j = 0; j<len; ++j){
            charS[s[j]]++;
            ans[lenAns++] = s[j];
        }
        while(j < lenS){
            int countChar[1000] = {0};
            for(int countJ = 0; countJ<len; ++countJ){
                j++;
                countChar[s[j-1]]++;
                if(charS[s[j-1]] < countChar[s[j-1]]){
                    check = 0;
                    break;
                }
            }
            if(!check)
                break;
        }
        if(check){
            cout << ans;
            return;
        }
    }
    cout << -1;
}

int main(){
    sov();
}
//greater <int>
