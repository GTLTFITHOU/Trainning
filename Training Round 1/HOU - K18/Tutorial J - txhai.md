# Incremental Induction
https://open.kattis.com/problems/incrementalinduction

## Tóm tắt đề bài

Có n người chơi cùng chơi một trò chơi, trong đó, tất cả người chơi đều chơi đúng một trận với n - 1 người còn lại, kết quả chỉ có thắng và thua.

Đề bài cho ta n là số người chơi và kết quả các cặp đấu giữa n người chơi.

Đề yêu cầu tìm cách sắp xếp n người chơi sao cho, theo thứ tự đó ta tách lần lượt từng người chơi từ tập A (ban đầu bao gồm n người chơi) sang 1 tập mới B, tại mọi thời điểm có tối đa k người chơi ở tập A đã chiến thắng B, ta cần tìm cách sắp xếp sao cho k là bé nhất.

Ta chỉ cần in ra số k.

## Lời giải

(1) Với ý "tất cả người chơi đều chơi đúng một trận với n - 1 người còn lại" ta có thể form dữ liệu đầu vào một đồ thị có hướng đầy đủ ( là đồ thị mà một đỉnh có chính xác một cạnh tới các đỉnh còn lại )
Với một cạnh có hướng từ U -> V sẽ có ý nghĩa là U đã thắng V.

### Tại một thời điểm đang tách ta có tập A và B, làm thế nào để tính được k.

Khi chia n người chơi ra làm hai tập A, B. Với các đỉnh ở tập A ta có thể đếm các cạnh đi ra từ A (từ A đi các đỉnh khác, tức là A thắng một ai đó) hay còn gọi là out degree, gọi tổng out degree của tất cả các đỉnh thuộc A là DO(A). DO(A) có thể chia làm 2 phần DO(A) = DO(X) +DO(Y), với X là các đỉnh thuộc A và Y là các đỉnh thuộc B. Dễ thấy k ở đây chính là DO(Y), ta cần tính DO(Y). Ta có thể dễ dàng tính DO(A) từ input để bài, DO(X) bằng ý (1), từ đó ta tính được DO(Y) = DO(A) - DO(X).

- Tính DO(X) bằng ý (1) : Trong đồ thị có hướng đầy đủ (lưu ý khi tách một tập con các đỉnh của đồ thị có hướng đầy đủ ta vẫn thu được đồ thị có hướng đầy đủ) thì DO(X) hay tổng out degree bằng $\binom{n}{2}$ với n là số lượng đỉnh. ![Imgur](https://i.imgur.com/pFSyS23.png)

  Trong hình trên tập A bao gồm 3 đỉnh 1, 4, 5. Ta có thể thấy k lúc này bằng 3( 5 - > 2, 1 -> 2, 1 -> 3). 

### Sắp xếp như thế nào để k bé nhất có thể trong khi tách.

Để ý sự thay đổi khi tách một đỉnh **U** 1từ A sang B, DO(Y) = DO(A) - DO(X), ta thấy độ giảm của X càng lớn khi số lượng đỉnh trong tập càng lớn.

Vd: A đang có 15 phần tử, khi chuyển 1 phần tử sang B, DO(X) giảm từ DO(15) = 105, xuống DO(14) =  91 , DO(15) - DO(14) = 14, DO(14) - DO(13) = 13,  DO(13) - DO(12) = 12.

Với công thức  DO(Y) = DO(A) - DO(X), để DO(Y) ít biến động nhất ta sẽ tách các đỉnh từ A sang B theo thứ tự giảm dần. DO(A) lớn ta sẽ trừ đi DO(X) lớn, DO(A) bé ta sẽ trừ đi DO(X) bé., 









### Code

Để thuận tiện, thì ta duyệt theo chiều ngược lại và sắp xếp theo thứ tự tăng dần.

```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define ms(arr,val) memset(arr,val,sizeof(arr))
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> outdegree(n,0);
    for(int i = 1 ; i <= n - 1;  i++){
        string s;
        cin>>s;
        for(int j = 0 ; j < i ; j++){
            outdegree[ s[j] == '1' ? i : j ] ++;
        }
    }

    sort(outdegree.begin(),outdegree.end());
    int ans = 0;
    int cur = 0;
    for(int i = 0 ; i < n ; i++){
        cur += outdegree[i];
        cur -= i;
        ans = max(ans,cur);
    }

    cout<<ans;
}
```





### Tài liệu tham khảo

- https://nordic.icpc.io/ncpc2019/ncpc19slides.pdf
- https://en.wikipedia.org/wiki/Tournament_(graph_theory)
