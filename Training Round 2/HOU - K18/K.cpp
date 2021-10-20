#include <bits/stdc++.h>
using namespace std;

int W, N;

struct Line
{
    int a, b, c;
    Line() {}
    Line(int x1, int y1, int x2, int y2)
    {
        int u = y1 - y2;
        int v = x2 - x1;
        this -> a = u;
        this -> b = v;
        this -> c = -u * x1 - v * y1;
    }

    bool operator==(const Line &rhs) const {
        return a * rhs.b == rhs.a * b &&
               a * rhs.c == rhs.c * a;
    }

    bool operator!=(const Line &rhs) const {
        return !(rhs == *this);
    }

    bool is_parallel(const Line &rhs) const
    {
        return (a * rhs.b == b * rhs.a);
    }
};

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> W >> N;
    vector<array<int, 4>> v;
    bool all_parallel = true;
    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bool oke = true;
        for (int j = 0; j < v.size(); j++)
            if (Line(x1, y1, v[j][0], v[j][1]) == Line(v[j][0], v[j][1], v[j][2], v[j][3]) && Line(x2, y2, v[j][0], v[j][1]) == Line(v[j][0], v[j][1], v[j][2], v[j][3]))
                oke = false;
        if (oke)
            v.push_back(array<int, 4> {x1, y1, x2, y2});
        if (!Line(x1, y1, x2, y2).is_parallel
        (Line(v[0][0], v[0][1], v[0][2], v[0][3])))
            all_parallel = false;
    }
    int cnt = 0, add = 0;
    if (all_parallel)
    {
        cnt = v.size() + 1;
        add = cnt;
    }
    else
    {
        cnt = 2 * v.size();
        add = 2;
    }
    int ans = 0;
    while (cnt < W)
    {
        ++ans;
        cnt += add;
        add = 2;
    };
    cout << ans << "\n";

    return 0;
}
