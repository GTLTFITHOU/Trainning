## Even Path

# Incremental Induction
https://codeforces.com/contest/1252/problem/C
## Tóm tắt đề bài
 Được cung cấp N (2 <= N <= 100K )  điểm  và Q ( 1 <= Q <=100K ) truy vấn.
- Được cung cấp 2 mảng a[i] và b[i]  (1<=i<=N) tạo thành ma trận N*N số 
 biết tại vị trí Arr[i][j] = a[i] + b[j]; 
- Q truy vấn mỗi truy vấn ra,ca,rb,cb là tọa độ của điểm A=Arr[ra][ca] và B = Arr[rb][cb].
* Biết tại vị trí Arr[i][j] mỗi bước chỉ có thể di chuyển được 1 ô liền kề và ô liền kề phải là số chẵn. 
## Yêu cầu
 Trả lời cho mỗi truy vấn có thể đi từ điểm A đến điểm B được hay không
## Giải thuật.
- Áp dụng giải thuật Disjoint Set (DSU) 

## Nhận xét:
- Trong ma trận N*N chỉ có các ô chẵn mới có thể di chuyển được.
- Các ô trong ma trận được tạo thành từ 2 mảng a và b. 
- Chẵn + chẵn = chẵn hoặc lẻ + lẻ = chẵn. 
- Di chuyển sang ngang được khi và chỉ khi b[i] và b[i+1] ( hoặc b[i] và b[i-1] ) cùng chẵn hoặc cùng lẻ.
- Di chuyển theo chiều thẳng đứng được khi  a[i] và a[i+1] ( hoặc a[i] và a[i-1] cùng chẵn hoặc cùng lẻ.
## Lời giải:
- Chúng ta sẽ sử dụng bộ 2 DSU của mảng a và mảng b để kiểm tra.
- Xét theo hàng : Nếu hàng của A và hàng của B có chung 1 đỉnh => (1) true
- Xét theo cột: Nếu cột của A và cột của B có chung 1 đỉnh => (2) true
- Nếu cả (1) và (2) đều đúng -> điểm A có thể đến điểm B và ngược lại không
-vd:
![image]https://drive.google.com/uc?export=view&id=1HXmgZSFsxUk9J0rVrvab3YNJAdtsr3G-
* Ta có 2 truy vấn :
	2 2 4 2 = NO 
	2 1 2 3 = YES
- trong ví dụ đầu tiên ta có thể thấy điểm A và điểm B xét theo cột chung gốc là 2 nhưng xét theo hàng lại không có có sự kết nối => NO 
- trong ví dụ thứ 2. Xét theo hàng ta thấy hàng 1 và hàng 2 liên thông với nhau và khi xét theo cột có cột 2 và 3 liên thông nhau => YES
# CODE
``` cpp 
#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 17/10/2021
* @contest: Practice
**/
using namespace std;
typedef   long long ll;
typedef   pair<int,int> ii;
typedef   vector<ii> vii;
typedef   unsigned long long ull;
#define ins(x)  insert(x);
#define endl  '\n'
#define tup tuple<int,int,int>
#define pb push_back
#define rsz resize
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define TC 0
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;
const int Nmax= 100*1000+100;
int a[Nmax],b[Nmax],par1[Nmax],par2[Nmax];
int root1(int v){
    return par1[v]? par1[v]=root1(par1[v]) : v;
}
int root2(int v){
    return par2[v]? par2[v]=root2(par2[v]) : v;
}
void Merge1(int u, int v){
    u=root1(u), v= root1(v);
    if(u==v) return;
    if(u>v) swap(u,v);
    par1[v]=u;
}
void Merge2(int u, int v){
    u=root2(u), v= root2(v);
    if(u==v) return;
    if(u>v) swap(u,v);
    par2[v]=u;
}
 
void solve()
{
    int N,Q;
    cin>>N>>Q;
    for(int i=1;i<=N;++i){cin>>a[i];}
    for(int i=1;i<=N;++i){cin>>b[i];}
    for(int i=1;i<N;++i){
        if(a[i]%2 == a[i+1]%2){
            Merge1(i,i+1);
        }
        if(b[i]%2 == b[i+1]%2){
            Merge2(i,i+1);
        }
    }
    int ra,ca,rb,cb;
    while(Q--){
        cin>>ra>>ca>>rb>>cb;
        int A,B,C,D;
        A=root1(ra);
        B=root2(ca);
        C=root1(rb);
        D=root2(cb);
        if(A==C && B==D){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
 
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    if(TC){
        int T;
        cin>>T;
        while(T--) solve();
    }else{
        solve();
    }
return 0;
}

``` 






 

