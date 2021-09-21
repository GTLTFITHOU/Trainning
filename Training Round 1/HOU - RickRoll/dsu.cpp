/*
    author:  Hang
    created: #
*/

#include<bits/stdc++.h>
using namespace std;

ifstream fi("");
ofstream fo("");

vector<int> dsu;

int par(int v) {
    if(dsu[v] == -1)
        return v;

    dsu[v] = par(dsu[v]);

    return dsu[v];
}

void un(int u, int v) { //merge
    u = par(u);
    v = par(v);

    if (u == v)
        return;

    dsu[u] = v;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> vec;

    for(int i = 0; i < n; ++i)
        dsu.push_back(-1);

    int a, b, c;

    for(int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        vec.push_back({c, {a, b}});
    }

    sort(vec.begin(), vec.end());

    int pv = 0;

    for(auto value : vec)
    {
        if(par(value.second.first) != par(value.second.second))
        {
            un(value.second.first, value.second.second);
            pv = max(pv, value.first);
        }
    }

    for(int i = 1; i < dsu.size(); ++i)
        if(par(i - 1) != par(i))
        {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }

    cout << pv << '\n';

    return 0;
}
