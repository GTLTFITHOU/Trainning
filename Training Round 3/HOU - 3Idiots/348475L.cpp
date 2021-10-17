#include<bits/stdc++.h>
using namespace std;
#define ll long long

/**
    @created: gatapcode
**/

int main()
{
    int t,btt,ctt,att;
    cin >> t;
    for(int i = 0,a,b,c ; i < t ; i++ ){
        cin >> a >> b >> c;
       ll mn = 9999999999;
        for(int j = 0 ; j <= a ; j++){
                att = a;
                att -= j;
            for(int k = 0 ; k <= b ; k++){
                 btt = b + j;
                ctt = c;
                btt -= k;
                ctt += k;
                mn = min(mn,(ll)max({att,btt,ctt}));

            }

        }
        for(int j = 0 ; j <= c ; j++){
                ctt = c;
                ctt -= j;
            for(int k = 0 ; k <= b ; k++){
                 btt = b + j;
                att = a;
                btt -= k;
                att += k;
                mn = min(mn,(ll)max({att,btt,ctt}));

            }

        }
        att = a;
        ctt = c;
        btt = b;
        while(btt > 0){
            if(att > ctt){
                ctt++;
            }
            else{
                att++;
            }
            btt--;
           mn = min(mn,(ll)max({att,btt,ctt}));
        }
        cout<<mn<<endl;
    }
}
