# Building Boundaries
https://open.kattis.com/problems/buildingboundaries

## Tóm tắt đề bài

Thắng Phan muốn mua 1 mảnh đất hình chữ nhật và dựng 3 tòa nhà trên mảnh đất ấy.
Diện tích của mỗi tòa nhà tương ứng với a1×b1, a2×b2, and a3×b3. Chúng có thể nằm cạnh nhau nhưng không được nằm đè lên nhau.
Các mảnh đất này cũng có thể xoay theo chiều dọc và chiều ngang.
Tính diện tích mảnh đất hình chữ nhật bé nhất mà Thắng Phan phải mua để có thể xây 3 toà nhà trong mảnh đất đó.

## Lời giải

Cách giải chia làm 2 case chính :
Case 1: Dàn 3 hình ra theo thứ tự trên 1 đường thẳng:
        Duyệt trâu tất cả các cách xoay của các hình như hình vẽ:
![image](https://drive.google.com/uc?export=view&id=1B8pQoaZ4lw5Yh2UNk9aD6RrNRnMNTLTO)
=>  Tại mỗi bước xoay ta sẽ có a1, b1, a2, b2, a3, b3 khác nhau. 
    Diện tích sẽ bằng: (a1 + a2 + a3) * max_3(b1, b2, b3); (chiều dài bằng tổng chiều dài 3 hình, cao bằng max của 3 chiều cao)

Case 2: Dàn 2 hình theo đường thẳng, hình 1 cao hơn hình 2 (nếu hình 1 thấp hơn thì swap 2 hình) hơn xếp trước.
        Hình thứ 3 sẽ đặt trên hình thứ 2. Ta cũng duyệt trâu tất cả các cách xoay của các hình.
![image](https://drive.google.com/uc?export=view&id=1dx1XpoaN1OU86OMn-2YXvulgKNCgT-us)
=> Tại mỗi bước xoay ta sẽ có a1, b1, a2, b2, a3, b3 khác nhau. 
    Diện tích sẽ tính bằng:
        Chiều cao : max độ cao của hình 1 với tổng độ cao của hình 2 và 3
        Chiều dài : độ dài của hình 1 + max độ dài của hình 2 và hình 3
    
Tại mỗi bước tính diện tích. Ta lưu res = min của các kết quả trên và đưa ra đáp án.

## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define see(x) cout << #x << " = " << x << ' ';
#define seen(x) cout << #x << " = " << x << '\n';
#define UWU cout << '\n';
#define endl cout << '\n';
#define fi first
#define se second
const ll MAX_N = 100100;
const ll MULTI_TESTS = 1;
const ll MOD = 1e9 + 7;
const ll H = 998244353;
const ll MAX_CHAR = 26;
ll max_3(ll a, ll b, ll c) {
    return max(a, max(b, c));
}
ll min_3(ll a, ll b, ll c) {
    return min(a, min(b, c));
} 
ll cal_align(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
    return (a1 + a2 + a3) * max_3(b1, b2, b3);
}
ll cal_2(ll h1, ll h2, ll wd, ll wu1, ll wu2, ll wid, ll hei) {
    ll width, height;

    if (h1 == h2) {
        width = max(wd, wid);
        height = h1 + hei;
        return width * height;
    }
    width = wu1 + max(wid, wu2);
    height = max(h2 + hei, h1);

    return width * height;
}
ll cal_com(ll a1, ll b1, ll a2, ll b2, ll a3, ll b3) {
    ll ans = ULONG_LONG_MAX;

    // h1, h2
    ll h1, h2, wd, wu1, wu2;
    h1 = max(a1, a2);
    h2 = min(a1, a2);
    wd = b1 + b2;
    wu1, wu2;
    if (h1 == a1) {
        wu1 = b1;
        wu2 = b2;
    } else {
        wu1 = b2;
        wu2 = b1;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a3, b3));

    // h2, h3
    h1 = max(a2, a3);
    h2 = min(a2, a3);
    wd = b2 + b3;
    wu1, wu2;
    if (h1 == a2) {
        wu1 = b2;
        wu2 = b3;
    } else {
        wu1 = b3;
        wu2 = b2;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a1, b1));

    // h1, h3
    h1 = max(a1, a3);
    h2 = min(a1, a3);
    wd = b1 + b3;
    wu1, wu2;
    if (h1 == a1) {
        wu1 = b1;
        wu2 = b3;
    } else {
        wu1 = b3;
        wu2 = b1;
    }
    ans = min(ans, cal_2(h1, h2, wd, wu1, wu2, a2, b2));
    return ans;
}
void pdthang2000() {
    ll a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    ll res = ULONG_LONG_MAX;
    // Case 1
    res = min(res, cal_align(a1, b1, a2, b2, a3, b3));
    res = min(res, cal_align(a1, b1, a2, b2, b3, a3));
    res = min(res, cal_align(a1, b1, b2, a2, b3, a3));
    res = min(res, cal_align(a1, b1, b2, a2, a3, b3));
    res = min(res, cal_align(b1, a1, b2, a2, b3, a3));
    res = min(res, cal_align(b1, a1, b2, a2, a3, b3));
    res = min(res, cal_align(b1, a1, a2, b2, b3, a3));
    res = min(res, cal_align(b1, a1, a2, b2, a3, b3));
    // Case 2
    res = min(res, cal_com(a1, b1, a2, b2, a3, b3));
    res = min(res, cal_com(a1, b1, a2, b2, b3, a3));
    res = min(res, cal_com(a1, b1, b2, a2, b3, a3));
    res = min(res, cal_com(a1, b1, b2, a2, a3, b3));
    res = min(res, cal_com(b1, a1, b2, a2, b3, a3));
    res = min(res, cal_com(b1, a1, b2, a2, a3, b3));
    res = min(res, cal_com(b1, a1, a2, b2, b3, a3));
    res = min(res, cal_com(b1, a1, a2, b2, a3, b3));
    cout << res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if (MULTI_TESTS) {
        ll Q;
        cin >> Q;
        while (Q--) {
            pdthang2000();
            endl;
        }
    } else {
        pdthang2000();
    }
}
```

## Tài liệu tham khảo
- Hình học cơ bản : toán hình cấp 2 + cấp 3 + trí tưởng tượng của bạn