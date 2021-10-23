#include <bits/stdc++.h>
/**
* @author: huykhanh
* @create: 6/10/2021
* @contest: practice
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
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define sz(x) (int)(x).size()
#define f first
#define s second
#define prec(n) fixed<<setprecision(n)
#define debug(n) cout<<(n)<<" "
#define debugn(n) cout<<(n)<<"\n";
// sortpair(v) sort(v.begin(), v.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) { return left.second < right.second; });
const int mod = (int) 1e9 + 7;
const ll MOD = 972663749;
//vector<vector<int>> a(101,vector<int>(100));


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
void huykhanh(){
    int T;
    //cin>>T;
    T=1;
    while(T--) solve();
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    huykhanh();
return 0;
}
