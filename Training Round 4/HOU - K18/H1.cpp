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
    auto oke = [&](long double m)
    {
        long double two_building = 0;
        for (int i = 1; i <= N; i++)
            two_building = max(two_building, v[i].first / 2 * v[i].second);
        if (two_building >= m)
            return true;
        vector<pair<long double, long double>> a;
        a.emplace_back(0, 0);
        for (int i = 1; i <= N; i++)
            if (v[i].first * v[i].second >= m)
                a.push_back(v[i]);
        vector<long double> max_suffix(a.size() + 5, 0);
        for (int i = a.size() - 1; i >= 1; i--)
            max_suffix[i] = max(max_suffix[i + 1], a[i].second);
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i].first * min(a[i].second, max_suffix[i + 1]) >= m)
                return true;
        }
        return false;
    };
    long double l = 0, r = 1e18, res = 0;
    for (int i = 0; i <= 100; i++)
    {
        long double m = (l + r) / 2;
        if (oke(m))
        {
            res = m;
            l = m;
        }
        else
            r = m;
    }
    cout << fixed << setprecision(1) << res;


    return 0;
}