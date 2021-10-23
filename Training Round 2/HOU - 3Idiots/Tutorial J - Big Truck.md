# Incremental Induction
https://open.kattis.com/problems/bigtruck
## Tóm tắt đề bài
Cho n ~(2 <= n <= 100)~ địa điểm (đỉnh) và mỗi điểm có a[i] vật phẩm. Chúng ta được cung cấp m đường đi
từ địa điểm x đến địa điểm y ( hoặc ngược lại) và khoảng cách giữa 2 địa điểm này.

## Yêu cầu
Tìm đường đi ngắn nhất từ điểm 1 đến điểm n và thu thập được nhiều vật phẩm nhất. Nếu không thể đi từ
điểm 1 đến điểm n hãy in ra "impossible".

## Giải thuật.
 Áp dụng thuật toán Djikstra để tìm đường đi ngắn nhất và greedy tìm số lượng vật phẩm nhiều nhất

## Cấu trúc dữ liệu 
``` cpp
/** 
a[i] là  vật phẩm tại điểm i
b[i] là khoảng cách từ ngắn nhất từ đỉnh 1 đến đỉnh i  (khởi tạo ban đầu là vô cùng: trong bài này là 1e9)
can[i] là số lượng vật phẩm có thể lấy được nhiều nhất tại điểm i
used[i] chỉ trạng thái của đỉnh i đã được duyệt hay chưa 
*/
int a[110],b[110],can[110]; 
bool used[110];
```

``` cpp
/** (I) chúng ta sẽ lưu lại khoảng cách và đỉnh được duyệt */
    priority_queue<pair<int,int>> q; 
// {-d(1y),y}  đoạn đường từ đỉnh 1 đến y và đỉnh y. Ta lưu dưới dạng số âm để ưu tiên các đoạn đường ngắn nhất sẽ ở đầu danh sách
```

``` cpp
/**(II) mảng này để lưu lại trạng thái từ đỉnh x đến y và khoảng cách d */
    vector<vector<pair<int,int>>> adj(110); 
```

## Lời giải
```
- B1: Ta xét các vị trí xe có thể đi qua trong cấu trúc (I) ở trên. Ban đầu xe ở đỉnh 1 và số vật phẩm có
  thể thu thập là can[1]=a[1] như vậy đỉnh khả thi lúc đầu là đỉnh 1.
- B2: ta xét các đoạn đường khả thi d(1x) với các đỉnh y ( là các đỉnh được nối trực tiếp với đỉnh x) và 
  đánh dấu đỉnh x đã được xét để tránh tình trạng lặp lại đỉnh đã xét. 
- B3: nếu đoạn đường từ 1 đến y thông qua x ngắn hơn đoạn đường của y hiện tại hoặc đoạn đường bằng nhau 
  nhưng thu thập được nhiều vật phẩm hơn thì ta coi đoạn đường này là đoạn đường khả thi và lưu vào trong cấu trúc dữ liệu. 
- B4: Tiếp tục xét các đoạn đường khả thi đến khi không còn đoạn đường nào khả thi mà chưa được đánh dấu.
- B5: đưa ra kết luận. Nếu khoảng cách của đỉnh n vẫn là vô cùng (1e9) thì chứng minh không thể đi từ đỉnh 1 đến đỉnh n. 
```

```cpp
    q.push({0,1}); // khởi tạo khoảng cách 0 tại đỉnh 1
    can[1]=a[1]; // đỉnh 1 thu được vật phẩm a[1] 
    
     while(!q.empty()){
            x=q.top().second; q.pop(); // x : đỉnh cần duyệt
        if(used[x]) continue; // đỉnh này đã được duyệt thì bỏ qua
        used[x]=true; // đánh dấu đỉnh n
	
        for(auto u : adj[x] ){ // chúng ta đi qua tất cả các đỉnh nối với đỉnh x
             y= u.f, d=u.s; // y: là đỉnh được nối với x,  d: khoảng cách đỉnh x đến y
             
	    if(b[x] +d < b[y]){
                can[y]=can[x]+a[y];
                b[y]= b[x]+d;
                q.push({-b[y],y});
             }else if(b[x] + d == b[y]){
                if(can[x] + a[y] > can[y]){
                    can[y]= can[x]+a[y];
                    q.push({-b[y],y});
                }
             }
        }
    }
```

# CODE
``` cpp
#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 6/10/2021
* @contest: practice
**/
using namespace std;
#define f first
#define s second

/** 
a[i] là  vật phẩm tại điểm i
b[i] là khoảng cách từ ngắn nhất từ đỉnh 1 đến đỉnh i  
can[i] là số lượng vật phẩm có thể lấy được nhiều nhất tại điểm i
used[i] chỉ trạng thái của đỉnh i đã được duyệt hay chưa 
*/
int a[110],b[110],can[110]; 
bool used[110];
void solve()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]; 
        b[i]=1e9; // khoảng cách của đỉnh i ban đầu được coi là vô cùng
    }
    b[1]=0; // khoảng cách của đỉnh 1 bằng ( đỉnh 1 đến đỉnh 1 không có sự thay đổi ) 
    cin>>m; 
    int x,y,d;

    /** chúng ta sẽ lưu lại khoảng cách và đỉnh được duyệt */
    priority_queue<pair<int,int>> q;  

    /** mảng này để lưu lại trạng thái từ đỉnh x đến y và khoảng cách d */
    vector<vector<pair<int,int>>> adj(110); 
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>d;
        adj[x].pb({y,d}); 
        adj[y].pb({x,d});
    }

    q.push({0,1}); // khởi tạo khoảng cách 0 tại đỉnh 1
    can[1]=a[1]; // đỉnh 1 thu được vật phẩm a[1] 
    while(!q.empty()){
            x=q.top().second; q.pop(); // x : đỉnh cần duyệt
        if(used[x]) continue; // đỉnh này đã được duyệt thì bỏ qua
        used[x]=true; // đánh dấu đỉnh n

        for(auto u : adj[x] ){ // chúng ta đi qua tất cả các đỉnh nối với đỉnh x
             y= u.f, d=u.s; // y: là đỉnh được nối với x,  d: khoảng cách đỉnh x đến y
             if(b[x] +d < b[y]){  
                can[y]=can[x]+a[y];
                b[y]= b[x]+d;
                q.push({-b[y],y});
             }else if(b[x] + d == b[y]){
                if(can[x] + a[y] > can[y]){
                    can[y]= can[x]+a[y];
                    q.push({-b[y],y});
                }
             }
        }
    }
    if(b[n]==1e9){
        cout<<"impossible";
        return;
    }
    cout<<b[n]<<" "<<can[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
return 0;
}


```





 

