#include <iostream>
#include <vector>
#include <array>
 
using namespace std;
 
int b, d, c, l;
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
 
    cin >> b >> d >> c >> l;
    vector<array<int, 3>> res;
    for (int i = 0; i <= l / b; i++)
        for (int j = 0; j <= l / d; j++)
            for (int k = 0; k <= l / c; k++)
                if ((i * b + j * d + k * c) == l)
                    res.push_back(array<int, 3> {i, j, k});
    if (res.empty())
        cout << "impossible";
    else
        for (int i = 0; i < (int) res.size(); i++)
            cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << "\n";
 
    return 0;
}