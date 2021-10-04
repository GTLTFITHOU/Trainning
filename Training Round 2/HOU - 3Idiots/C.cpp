#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){

int a,b,c,d;
cin >> a >> b >> c >> d;
int cnt = 0;
for(int i = 0 ; i <= d/a ; i++){
    for(int j = 0 ; j <= d/b ; j++){
        for(int k = 0 ; k <= d/c ; k++){
            if(i*a + j*b + k*c == d){
                    cnt++;
                cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
}
if(cnt == 0){
    cout<<"impossible";
}

}