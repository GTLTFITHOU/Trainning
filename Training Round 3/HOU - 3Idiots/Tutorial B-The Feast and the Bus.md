## The Feast and the Bus

# Incremental Induction
https://codeforces.com/contest/1250/problem/B
## Tóm tắt đề bài
- Cho n (1<= n <= 500000)  người là thành viên của k (1<=8000) câu lạc bộ.
- chứa n số nguyên dương : t[i] biết (1<= i <=n ) là thành viên i ở câu lạc bộ t[i]  (1 <= t[i] <= k)
## Yêu cầu
- Tính chi phí thuê 1 xe để đưa tất cả các nhân viên của công ty đi đến bữa tiệc. Biết mỗi lần di chuyển đến bữa tiệc sẽ tốn 
 ( số ghế của xe * số chuyến đi ) chi phí. Và được biết mỗi lần di chuyển xe không thể chứa quá 2 nhóm và không có nhóm nào bị tách ra. 

## Giải thuật.
- Thuật toán Greedy (Tham lam) là giải pháp hữu hiệu cho bài toán này. Khi đề bài yêu cầu tìm 1 giải pháp tối ưu. 

## Cấu trúc dữ liệu 
 ```cpp 
	/**
		Đặc điểm tương tự cấu trúc dữ liệu set nhưng với multiset ta có thể lưu lại các số trùng lặp nhau được.
	*/
	multiset<int> st;
 ```

## Lời giải
- Nhận thấy chúng ta có thể giảm chi phí bằng cách tăng số ghế của xe hoặc tăng số chuyến đi. Và số đội ta có là 8000 một con số tương đối 
nên giải pháp khả thi là ta có thể tính các qua tất cả số ghế có thể từ 1 đến 500K thì tốn chi phí 500k*8k =400M  và dễ nhận thấy sẽ bị TLE.
Chúng ta có thể tối ưu hóa khoảng ghế để đạt được kết quả dựa vào thông số <i> mỗi lần di chuyển xe không thể chứa quá 2 nhóm và không có nhóm nào bị tách ra </i> 
và số lượng thành viên của mội đội ta tạm ước tính 500k/8k = 63 thành viên( tạm coi 100)
Nên chúng ta có thể xác định được khoảng sau khi sắp xếp lại các đội theo số lượng thành viên của đội tăng dần: 
- min = thành viên của đội k ( đội có đông thàn viên nhất) 
- max = thành viên của đội k + thành viên của đội k/2.
 Khi đó ta tốn chi phí tối đa 100*8k= 800K là khả thi.   

* Để tối ưu số chuyến nhất thì mỗi chuyến ta sẽ lấy đội đông nhất và lấy đội có số thành viên gần nhất với số ghế còn trống.  
# CODE
``` cpp 
#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 9/10/2021
* @contest: CLB
**/
using namespace std;
/**
    có n nhân viên  và k đội
    các đội đánh số từ 1 đến k
*/
ll check( multiset<int> st,ll m){
    ll res=0;
    while(!st.empty()){
        auto it = st.begin();
        if(*it>m) return 0;

        auto up = (st.upper_bound((m - *it) ));

        //cout<<*it<<" "<<*up<<" "<<m<<endl;
        if(up==st.end()) --up;
        while(up!=st.begin() && *up>(m-*it) ){
            --up;
        }
       // cout<<*it<<" - "<<*up<<endl;
        if( it!=up && *it + *up <=m){
            ++res;
            st.erase(it);
            st.erase(up);
        }else if(*it <=m){
            ++res;
            st.erase(it);
        }
    }
    return res;
}

void solve()
{
    int n,k,x;
    cin>>n>>k;
    vector<int> a(k+1,0);
    multiset<int> st;
    for(int i=0;i<n;++i){
        cin>>x;
        ++a[x];
    }
    ll sum=0;
    for(int i=1;i<=k;++i){
        st.insert(a[i]);
    }
    sort(all(a));

    ll ans=2e18,res=0,i=a[k];
    sum=a[k]+ a[k/2];
    for(;i<=sum;++i){
        if( (res= check(st,i)) ){
            ans=min(ans,res*i);
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
return 0;
}

``` 






 

