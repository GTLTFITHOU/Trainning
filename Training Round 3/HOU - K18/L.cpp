#include <bits/stdc++.h>
using namespace std;
 
int T;
 
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int res = max({a, b, c});
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 && j == 0)
                continue;
            res = min(res, max({a - i, i + j, b - j + c}));
        }
    }
    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i == 0 && j == 0)
                continue;
            res = min(res, max({c - i, i + j, b - j + a}));
        }
    }
    for (int i = 0; i <= b; i++)
    {
        res = min(res, max((b - i + c + 1) / 2, a + i));
        res = min(res, max((b - i + a + 1) / 2, c + i));
    }
    cout << res << "\n";
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> T;
    while (T--)
    {
        solve();
    }
 
    return 0;
}
