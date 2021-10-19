#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
pair<long double, long double> v[maxn];

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > v[i].second)
            swap(v[i].first, v[i].second);
    }
    sort(v + 1, v + N + 1, [&](pair<long double, long double> x, pair<long double, long double> y)
    {
       if (x.first == y.first)
           return x.second > y.second;
       return x.first < y.first;
    });
    long double res = 0;
    for (int i = 1; i <= N; i++)
        res = max(res, v[i].first / 2 * v[i].second);
    vector<long double> max_suffix(N + 5, 0);
    for (int i = N; i >= 1; i--)
        max_suffix[i] = max(max_suffix[i + 1], v[i].second);
    for (int i = 1; i <= N; i++)
        res = max(res, v[i].first * min(v[i].second, max_suffix[i + 1]));
    cout << fixed << setprecision(1) << res;

    return 0;
}