#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 
 
int main()
{
    int n;
    cin >> n;
    ll ans = 9999999999;
    for(int i = 1 ; i <= sqrt(n) ; i++){
        if(n % i == 0){
            ans = min(ans,(ll)2*i + 2*(n/i));
        }
    }
    cout<<ans<<endl;
}