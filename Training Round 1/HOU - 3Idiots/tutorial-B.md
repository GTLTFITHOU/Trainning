# Incremental Induction
https://open.kattis.com/contests/e9659r/problems/multigram
## Tóm tắt đề bài
Cho 1 chuỗi String s tối đa 100000 ký tự. Yêu cầu : chuỗi đã cho có phải từ đã nghĩa không ?
- Nếu không phải : in -1
- Nếu phải thì in ra gốc đã nghĩa ngắn nhất. ( từ đa nghĩa hình thành nên chuỗi s ). 
* Định nghĩa từ đa nghĩa : là một từ mà được ghép lại bởi các từ là đảo ngữ của nhau. 
* Định nghĩa đảo ngữ: là một từ hoặc cụm từ mà các chữ cái có thể được sắp xếp lại để thu được một từ khác

# Lập luận: 
- Từ đa nghĩa được hình thành bởi các từ là đảo ngữ của nhau.
  Vậy N ( N: độ dài của chuỗi s)  = x*n (n : độ dài của gốc đảo ngữ). (1) 
--> Từ (1) ta có thể thấy được độ dài gốc là các số bị N chia hết (N%x==0). Ta có thể hình thành được
danh sách các số mà N chia hết. 

* Chiến lược phổ biến để kiểm tra xem 2 từ có phải đảo ngữ của nhau hay không là so sánh kết quả sau khi 
sắp xếp lại  strA ="abc", strB="bca". Sau khi sắp xếp lại có strA="abc" và strB="abc" ==> là đảo ngữ của nhau.
Đề bài yêu cầu tìm từ gốc đảo ngữ bé nhất. 
Ta tách chuỗi s đã cho thành các chuỗi con n(đã tìm) và so sánh.
 Nếu các chuỗi con bằng nhau ta thu được kết quả còn không thì in -1; 

## Code
```
#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create:
**/
using namespace std;
typedef   long long ll;
typedef   unsigned long long ull;
#define endl  '\n'
#define  vi(x)  vector<int> x;
#define  pi   pair<int,int> x
#define tup tuple<int,int,int>
#define pb push_back
#define rsz resize
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)


set<int> a;
// hàm này tìm tất cả các gốc con có thể
void build(int n){
    int N=sqrt(n);
    for(int i=2;i<=N;++i){
        if(n%i==0){
            a.insert(n/i);
            a.insert(i);
        }
    }
}
void solve()
{
    string s;
    cin>>s;
    a.insert(1);
    build(sz(s));
    for(auto &x: a){
            map<string,int> mp; // khởi tạo 1 map để lưu kết quả chuỗi con sau khi sắp xếp 
            string str; 
        for(int i=0;i+x<=sz(s);i+=x){
            str = s.substr(i,x);
            sort(all(str));
            ++mp[str];
            if(mp.size() >1) break; // nếu kích thước của mp lớn hơn 1 thì có các từ không phải là đỏa ngữ của nhau
        }
        if(mp.size() == 1){ 
	// nếu kích thước của mp bằng 1 bài toán thỏa mãn tất cả các chuỗi con có độ dài n trong s là đảo ngữ của nhau
            cout<<(s.substr(0,x));
            return;
        }
    }
    cout<<-1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    //cin>>T;
    T=1;
    while(T--) solve();
return 0;
}
```

