# Semi-prime H-numbers
https://open.kattis.com/problems/hnumbers

## Tóm tắt đề bài

Ta định nghĩa H-numbers là số có dạng : 4*n + 1.

H-numbers cũng được chia thành 2 loại số : H-primes và H-composite.

H-primes được định nghĩa là : H-number khác 1 và là có thể phân tích theo duy nhất 1 cách là tích của số H-numbers : 1 * h.

Những số không phải H-primes thì là H-composite.

Ví dụ về những số H-composite: 5 * 5 = 25, 5 * 9 = 45, 5 * 13 = 65, 9 * 9 = 81, 5 * 17 = 85.

Bài toán yêu cầu là tính số lượng số H-semi-primes. Số H-semi-prime là tích của chính xác 2 số H-primes. 

Các số ở ví dụ trên đều là H-semi-prime, nhưng số 5 * 5 * 5 = 125 thì không vì nó là tích của 3 số H-primes.

## Lời giải

Đầu tiên để tính được số H-semi-primes, chúng ta cần tính các số H-primes, vậy làm sao để chúng ta biết với số x thì x có phải là số H-primes hay không ?

Đọc lại định nghĩa số H-number, ta thấy để số x là H-primes thì x không được chia hết cho các số H-primes < x và để tối ưu ta chỉ kiểm tra các số H-primes thoả mãn điều kiện sau: H-primes * H-primes <= x

Vậy ta cần một vector lưu trữ các số H-primes và duyệt tất cả các số H-numbers với mỗi số H-number ta kiểm tra xem có chia hết cho bất kì số nào có trong vector hay không nếu có bỏ qua, ngược lại thì push vào vector.

Như vậy ta đã lọc được tất cả các số H-primes. Việc còn lại là tìm các số H-semi-numbers.

Ta có thể chứng minh được rằng số lượng số H-semi-primes không quá lớn và có thể thực hiện tìm tất cả các số H-semi-primes bằng Bruteforce.
Chứng minh: mỗi lần duyệt a[i] với a[i] là số H-primes ta sẽ chạy vòng lặp tới max là: 1e6/a[i] với bước nhảy i += 4, vậy với mỗi a[i + 1], 1e6/a[i + 1] sẽ càng nhỏ và tiệm cận về 0.
Cuối cùng, ta phải loại bỏ các phần tử trùng lặp và dùng chặt nhị phân để đếm kết quả, hoặc tổng tiền tố để tính toán trước rồi in ra kết quả ở mỗi truy vấn.

## Code

```cpp

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> h_primes;
    h_primes.push_back(5);
    for (int i = 2; (4 * i + 1) < maxn; i++)
    {
        bool oke = true;
        int x = 4 * i + 1;
        for (int j = 0; j < h_primes.size() && h_primes[j] * h_primes[j] <= x; j++)
            if (x % h_primes[j] == 0)
            {
                oke = false;
                break;
            }
        if (oke)
            h_primes.push_back(x);
    }
    vector<int> h_semi_primes;
    for (int i = 0; i < h_primes.size(); i++)
        for (int j = i; j < h_primes.size(); j++)
            if (h_primes[i] * h_primes[j] <= maxn)
                h_semi_primes.push_back(h_primes[i] * h_primes[j]);
            else
                break;
    sort(h_semi_primes.begin(), h_semi_primes.end());
    h_semi_primes.erase(unique(h_semi_primes.begin(), h_semi_primes.end()), h_semi_primes.end());
    while(true)
    {
        int h;
        cin >> h;
        if (h == 0)
            return 0;
        auto ans = upper_bound(h_semi_primes.begin(), h_semi_primes.end(), h) - h_semi_primes.begin();
        cout << h << " " << ans << "\n";
    }
}

