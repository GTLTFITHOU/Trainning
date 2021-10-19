#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int N;
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> N;
    int ans = 1e18;
    for (int i = 1; i * i <= N; i++)
        if (N % i == 0)
            ans = min(ans, 2ll * (i + N / i));
    cout << ans << "\n";
 
    return 0;
}
