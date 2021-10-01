

# Driving Range

Link submit: [https://open.kattis.com/problems/drivingrange](https://www.youtube.com/watch?v=dQw4w9WgXcQ)

Another link: https://open.kattis.com/contests/e9659r/problems/drivingrange

## Tóm tắt đề bài

Cho <b>n</b> thành phố và <b>m</b> con đường. Các thành phố được đánh số từ <b>0</b> đến <b>n-1</b>. Cho biết các thành phố nối với nhau qua đường bộ và cho biết chiều dài của con đường (các con đường hai chiều có độ dài khác nhau).

## Yêu cầu

Tìm <i>khoảng cách tối thiểu</i> để ô tô đi <i>từ một thành phố này đến một thành phố khác</i>. Nếu không thể lái xe từ thành phố nào đó đến thành phố khác bất kể phạm vi của ô tô, thay vào đó hãy xuất một dòng có chứa từ <b>IMPOSSIBLE</b>. (Có thể hiểu rằng: Kiểm tra xem các thành phố có kết nối với nhau không. Nếu có thì in ra khoảng cách tối thiểu của ô tô, nếu ko thì xuất <b>IMPOSSIBLE</b>).

## Giải thuật: <i>Disjoint Set Union (DSU)</i>

Cấu trúc dữ liệu Disjoint Set Union (DSU) cho phép bạn thêm các cạnh vào một đồ thị trống ban đầu và kiểm tra xem hai đỉnh của đồ thị có được kết nối với nhau hay không.

### Tổ chức dữ liệu:

- Mảng vector<pair<int, pair<int, int>>> <b>vec<b>;  chứa danh sách đầu vào theo thứ tự chiều dài đường, a, b (a và b là 2 thành phố đc nối với nhau).
- Mảng vector<int> <b>dsu<b>;  tất cả thông tin về các tập hợp thành phố sẽ được lưu giữ trong mảng.
- int pv;   lưu phạm vi tối thiểu của ô tô. 

 ##Lời giải:

Có n người chơi cùng chơi một trò chơi, trong đó, tất cả người chơi đều chơi đúng một trận với n - 1 người còn lại, kết quả chỉ có thắng và thua.

Đề bài cho ta n là số người chơi và kết quả các cặp đấu giữa n người chơi.

Đề yêu cầu tìm cách sắp xếp n người chơi sao cho, theo thứ tự đó ta tách lần lượt từng người chơi từ tập A (ban đầu bao gồm n người chơi) sang 1 tập mới B, tại mọi thời điểm có tối đa k người chơi ở tập A đã chiến thắng B, ta cần tìm cách sắp xếp sao cho k là bé nhất.

Ta chỉ cần in ra số k.

## Lời giải

- Khởi tạo mảng dsu (Ban đầu chưa có thành phố nào được liên kết với nhau).
- Sắp xếp tăng dần thứ tự của đầu vào vì đề bài yêu cầu tìm phạm vi tối thiểu của ô tô. (Nghĩa là tìm con đường ngắn nhất giữa 2 thành phố kết nối với nhau nếu 2 thành phố này kết nối với nhau thông qua nhiều hơn 1 con đường và tìm con đường dài nhất trong tất cả các con đường kết nối).
- Kiểm tra xem các thành phố a và thành phố b có root khác nhau ko. Nếu khác nhau thì kết hợp 2 thành phố lại.
- Kiểu tra xem các thành phố có các root giống nhau không. Nếu không thì xuất IMPOSSIBLE. Nếu có thì hiện pv.

## Code 
 
```cpp
/*
    author:  Hang
    created: #
*/

#include<bits/stdc++.h>
using namespace std;

ifstream fi("");
ofstream fo("");

vector<int> dsu;

int par(int v) {
    if(dsu[v] == -1)
        return v;

    dsu[v] = par(dsu[v]);

    return dsu[v];
}

void un(int u, int v) { //merge
    u = par(u);
    v = par(v);

    if (u == v)
        return;

    dsu[u] = v;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> vec;

    for(int i = 0; i < n; ++i)
        dsu.push_back(-1);

    int a, b, c;

    for(int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        vec.push_back({c, {a, b}});
    }

    sort(vec.begin(), vec.end());

    int pv = 0;

    for(auto value : vec) {
        if(par(value.second.first) != par(value.second.second)) {
            un(value.second.first, value.second.second);
            pv = max(pv, value.first);
        }
    }

    for(int i = 1; i < dsu.size(); ++i)
        if(par(i - 1) != par(i)) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }

    cout << pv << '\n';

    return 0;
}

  
```
<div dir="rtl">
<b>written by Hang</b>
</div>
