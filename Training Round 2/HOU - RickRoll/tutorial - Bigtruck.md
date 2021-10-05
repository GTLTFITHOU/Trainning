

# Big Truck

Link submit: https://open.kattis.com/problems/bigtruck


## Tóm tắt đề bài

Cho N thành phố khác nhau được đánh số (1 <= i <= N), ở thành phố i có A[i] vật phẩm. Cho M con đường khác nhau, mỗi con đường biểu diễn bởi x, y ,z với x và y thể hiện có đường đi giữa 2 thành phố này. z là khoảng cách của 2 thành phố, đây là đồ thị không chu trình nên có thể đi từ x -> y cũng như y -> x.

## Yêu cầu

Tìm <i>đường đi ngắn nhất</i> của thành phố 1 và thành phố N. Nếu có nhiều con đường ngắn nhất thì chọn con đường <i>nhặt được nhiều vật phẩm nhất</i>. Nếu không có thì in ra impossible.

## Giải thuật: 

Mình dựa vào thuật toán Djikstra trong môn toán rời rạc để nghĩ ra ý tưởng của bài này. Cộng thêm 1 số kĩ thuật như dynamic programming(DP) và greedy để giải bài này. Djikstra là thuật toán tìm đường đi ngắn nhất khá hiệu quả, luôn tìm đường đi đến 1 đỉnh gần rồi dựa vào đó để tính đường đi ngắn nhất đến đỉnh tiếp theo.


### Tổ chức dữ liệu:

```cpp
struct vertex {
    int cur = -1; //lưu trữ đỉnh vừa thăm, sẽ có giá trị -1 nếu chưa được thăm
    int pick;//số vật phẩm đã nhặt
    int d;// quãng đường đã đi để tới được đỉnh cur
};
```

```cpp
vector<vector<int>> ma(n + 1, vector<int>(n + 1, 0));
//ma trận kề của N thành phố, ma[i][j] = 5 thể hiện có thể đi từ i đến j với quãng đường là 5
```

```cpp
vector<vertex>  shortest(n+1);
// lưu trữ đường đi ngắn nhất tới n đỉnh của đồ thị
```
```cpp
vector<vertex>  cur;
// lưu trữ các con đường vừa đi của bước trước.
```


 ##Lời giải:

- Ta tạo ma trận kề với từ M đường đi với ma[x][y]=ma[y][x]=z . Vì là đồ thị vô hướng nên ma[x][y]==ma[y][x].

- Như đã nói ở mỗi đỉnh ta sẽ luôn tính đường đi ngắn nhất, mình tạo 1 hàm để kiểm tra của đường đi hiện tại của đỉnh X nếu đường đi chưa có, ta chỉ cần thêm con đường đó, nếu đã có đường đi ta giữ lại đường đi ngắn nhất tới đỉnh X vào vector shortest thôi.

```cpp
    auto chk = [&] (vertex dj) {
        vertex tmp = shortest[dj.cur];
        if(tmp.cur == -1) {
            shortest[dj.cur] = dj;
            return 1;
        } else {
            if(dj.d < tmp.d) {
                shortest[dj.cur] = dj;
                return 1;
            } else if(dj.d == tmp.d && dj.pick > tmp.pick) {
                shortest[dj.cur] = dj;
                return 1;
            }
        }
        return 0;
    };
```
- Mình sử dụng lamda function giúp tiết kiệm hàm biết cần khai báo hơn.
- Sinh các đường đi có thể từ đỉnh 1 và đưa vào vector cur. Luôn kiểm tra đường đi ngắn nhất qua các đỉnh.
```cpp
   for(int i = 1; i <= n; i++) {
        if(ma[1][i]) {
            vertex vertex;
            vertex.cur = i;
            vertex.pick = a[i - 1] + a[0];
            vertex.d = ma[1][i];
            cur.pb(vertex);
            chk(vertex);
        }
    }
```

- Có thể thấy khi vector cur rỗng chính là lúc ta đã thăm tất cả đỉnh có thể từ đỉnh 1. Từ đó ta có thể hướng đến dùng thuật toán loang (BFS hay DFS gì đó). Còn mình thì dùng trâu để thử tất cả khả năng + DP, qua mỗi bước đêu tính đường đi ngắn nhất đến đỉnh đó.

```cpp
while(cur.size()) {
        set<int> vis;// các đỉnh đã thăm trong 1 lần duyệt
        for(int j = 0; j < cur.size(); j++) {
            for(int i = 1; i <= n; i++) {
                vertex vertex = cur[j];
                if(ma[vertex.cur][i] ) {
                    vertex.pick += a[i - 1];
                    vertex.d += ma[vertex.cur][i];
                    vertex.cur = i;
                    if(chk(vertex)) vis.ins(i);
                }
            }
        }
        cur.clear();
        for(auto i : vis) {
            cur.pb(shortest[i]);
        }
        //chỉ khi tìm được đường đi tối ưu hơn mới thêm vào set vis, sẽ đến lúc đã loang hết trường hợp và done
    }
```
- Đoạn này sẽ có đpt không quá (n^3*log(n)) vì chỉ cần thăm tối đa n đỉnh.( chắc thế :v )
- cuối cùng, chỉ cần in ra nếu vertex[n]=-1 thì impossible, ngược lại in ra đường đi ngắn nhất và số vật phẩm nhặt được.
## Full Code
```cpp
#include<bits/stdc++.h>
#define pb push_back
#define ins insert

using namespace std;

struct vertex {
    int cur = -1;
    int pick;
    int d;
};

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> ma(n + 1, vector<int>(n + 1, 0));
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ma[x][y] = ma[y][x] = z;
    }

    vector<vertex>  cur, shortest(n + 1);
    auto chk = [&] (vertex dj) {
        vertex tmp = shortest[dj.cur];
        if(tmp.cur == -1) {
            shortest[dj.cur] = dj;
            return 1;
        } else {
            if(dj.d < tmp.d) {
                shortest[dj.cur] = dj;
                return 1;
            } else if(dj.d == tmp.d && dj.pick > tmp.pick) {
                shortest[dj.cur] = dj;
                return 1;
            }
        }
        return 0;
    };

    for(int i = 1; i <= n; i++) {
        if(ma[1][i]) {
            vertex vertex;
            vertex.cur = i;
            vertex.pick = a[i - 1] + a[0];
            vertex.d = ma[1][i];
            cur.pb(vertex);
            chk(vertex);
        }
    }

    while(cur.size()) {
        set<int> vis;
        for(int j = 0; j < cur.size(); j++) {
            for(int i = 1; i <= n; i++) {
                vertex vertex = cur[j];
                if(ma[vertex.cur][i] ) {
                    vertex.pick += a[i - 1];
                    vertex.d += ma[vertex.cur][i];
                    vertex.cur = i;
                    if(chk(vertex)) vis.ins(i);
                }
            }
        }
        cur.clear();
        for(auto i : vis) {
            cur.pb(shortest[i]);
        }
    }

    if(shortest[n].cur != -1) {
        cout << shortest[n].d << " " << shortest[n].pick << endl;
    } else {
        cout << "impossible";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();

}

/*

*/
```

- Excution time: 0.00 s

<div dir="rtl">
<b>Written by Hung</b>
</div>
