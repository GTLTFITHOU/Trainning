#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 1e6;

int main(){    
    int cont[M+1];
    int div[M+1];
    cont[0]=0;
    div[0]=1;
    double lm;
    bool fd;
    for(int i=1,a=5;i<=M;i++,a+=4){
        lm=sqrt(4*i+1);
        fd=false;
        for(int j=5;j<=lm;j+=4)
            if(a%j==0){
                fd=true;
                div[i]=div[(a/j-1)/4]+1;
                break;
            }
        if(!fd) div[i]=1;
        if(div[i]==2) cont[i]=cont[i-1]+1;
        else cont[i]=cont[i-1];
    }
    int h;
    while(1){
       	cin >> h;
        if(h==0) break;
	    cout << h << ' ' << cont[(h-1)/4] << '\n';
    }
    
    return 0;
}
