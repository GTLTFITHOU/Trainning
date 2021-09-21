#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> a;
    a.push_back(5);
    for (int i = 2; (4 * i + 1) < maxn; i++)
    {
        bool oke = true;
        int x = 4 * i + 1;
        for (int j = 0; j < a.size() && a[j] * a[j] <= x; j++)
            if (x % a[j] == 0)
            {
                oke = false;
                break;
            }
        if (oke)
            a.push_back(x);
    }
    set<int> st;
    for (int i = 0; i < a.size(); i++)
        for (int j = i; j < a.size(); j++)
            if (a[i] * a[j] <= maxn)
                st.insert(a[i] * a[j]);
            else
                break;
    a.clear();
    for (auto e : st)
        a.push_back(e);
    while(true)
    {
        int h;
        cin >> h;
        if (h == 0)
            return 0;
        auto ans = upper_bound(a.begin(), a.end(), h) - a.begin();
        cout << h << " " << ans << "\n";
    }

}