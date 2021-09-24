# Buying Coke
https://open.kattis.com/problems/coke

## Tóm tắt đề bài

Phải mua C lon coca tại máy bán hàng với số lượng xu đã cho. 

Mỗi một lần bấm mua, máy chỉ trả ra 1 lon coca và tiền thừa (máy sẽ cố trả tiền thừa bằng ít xu nhất). 

Đề bài cho ta C là số lon coca ta phải mua (mỗi lon có giá 8 đồng) và số lượng xu mỗi loại: n1, n5, n10.

Đề yêu cầu ta tìm cách để số xu phải đưa vào máy là ít nhất.
Ta cần in ra số lượng xu ít nhất mà ta phải đưa vào máy để mua hết số lon coca.

## Lời giải

Để số lượng xu đưa vào máy là ít nhất, chúng ta sẽ dùng hết các xu có giá trị to rồi tới các xu có giá trị bé hơn.
#### Chúng ta có 4 cách mua cơ bản:
- Đưa 1 ‘xu10’. Máy sẽ trả 2 ‘xu1’.
- Đưa 2 ‘xu5’. Máy sẽ trả 2 ‘xu1’.
- Đưa 1 ‘xu5’ và 3 ‘xu1’.
- Đưa 8 ‘xu1’.

Ngoài ra, chúng ta còn 1 dữ kiện quan trọng là máy sẽ trả tiền thừa bằng ít xu nhất. Nên 
#### Chúng ta có thêm 1 cách mua đặc biệt nữa:
- Đưa 1 ‘xu10’ và 3 ‘xu1’. Máy sẽ trả 1 ‘xu5’.

#### Cách mua đặc biệt này ảnh hưởng thế nào tới kết quả ?
Ví dụ: Mua 2 lon coca với số lượng xu1, xu5, x10 lần lượt là 10, 0, 1. Trong trường hợp này, nếu chỉ với 4 cách mua cơ bản thì ta sẽ phải đưa 9 xu vào máy để mua 2 lon coca. Tuy nhiên, với cách mua đặc biệt kia, chúng ta chỉ cần đưa 8 xu vào máy để mua 2 lon coca.

## Code

 ```cpp
#include <bits/stdc++.h>
#define ff first
#define ss second
#define sz(x) x.size()
#define pb(x) push_back(x)
#define all(a) a.begin(),a.end()
#define setp(x) fixed << setprecision(x)

using namespace std;

typedef complex<long double> cd;
namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(long double& x) { string t; re(t); x = stold(t); }
	template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
		re(first); re(rest...);
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.ff,p.ss); }
	template<class T> void re(vector<T>& a) {
		for(auto &i:a)re(i);
	}
	template<class T, size_t SZ> void re(array<T,SZ>& a) {
		for(int i=0;i<SZ;++i) re(a[i]);
	}
}

using namespace input;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

namespace io
{
	void setIn(string s) { ifstream cin (s);}
	void setOut(string s) {ofstream cout (s);}
	void setIO(string s = "")
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin.exceptions(cin.failbit);
		if (sz(s)) setIn(s+".inp"), setOut(s+".out");
	}
}
using namespace io;

constexpr int mod = 1e9+7;

const int B = -1;
int mem[200][200][55];
int total;

//==============Đây mới là phần quan trọng nhé!!!==============
int MIN(int c, int n5, int n10) {
    if (c == 0) return 0;
    int n1 = total - n5 * 5 - n10 * 10;
    n1 = min(c * 8, n1);
    n5 = min(c * 2, n5);
    n10 = min(c, n10);
    if (mem[c][n5][n10] != B) return mem[c][n5][n10];
    int mn = c * 8;
    if (n10 > 0)
      mn = min(mn, 1 + MIN(c - 1, n5, n10 - 1));
    if (n5 >= 1 && n1 >= 3)
      mn = min(mn, 4 + MIN(c - 1, n5 - 1, n10));
    if (n5 >= 2)
      mn = min(mn, 2 + MIN(c - 1, n5 - 2, n10));
    if (n1 >= 8)
      mn = min(mn, 8 + MIN(c - 1, n5, n10));
    if (n10 >= 1 && n1 >= 3)
      mn = min(mn, 4 + MIN(c - 1, n5 + 1, n10 - 1));
    mem[c][n5][n10] = mn;
	return mn;
}

int main()
{
	setIO();
	srand(time(NULL));
	int t,c,n1,n5,n10;
	re(t);
    while (t--) {
      for(int i=0;i<200;++i)
		  for(int j=0;j<200;++j)
			  for(int k=0;k<55;++k)
				  mem[i][j][k]=B;
	  re(c); re(n1); re(n5); re(n10);
      total = n1 + n5 * 5 + n10 * 10;
      cout << MIN(c, n5, n10) << '\n';
    }
	return 0;
}
 



 




