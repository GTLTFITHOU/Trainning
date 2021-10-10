#include <bits/stdc++.h>
using namespace std;
 
int T;
vector<int> c(15, 0);
 
void solve()
{
    for (int i = 0; i <= 9; i++)
        cin >> c[i];
    ++c[0];
    for (int i = 1; i <= 9; i++)
        if (c[i] == 0)
        {
            cout << i << "\n";
            return;
        }
    int mn = 1e9;
    for (int i = 0; i <= 9; i++)
        mn = min(mn, c[i]);
    int pos_min;
    for (int i = 0; i <= 9; i++)
        if (c[i] == mn)
        {
            pos_min = i;
            break;
        }
    if (pos_min == 0)
    {
        string res = "1";
        res += string(c[0], '0');
        cout << res << "\n";
    }
    else
        cout << string(c[pos_min] + 1, (char)('0' + pos_min)) << "\n";
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
