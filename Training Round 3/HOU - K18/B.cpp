#include <bits/stdc++.h>
#define int long long
using namespace std;

int N, K;

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;
    vector<int> group(K);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        --x;
        ++group[x];
    }
    sort(group.begin(), group.end());
    int ans = 1e18;
    for (int i = K / 2; i <= K; i++)
    {
        int two_team = -1;
        for (int j = 0; j <= i; j++)
            if (K - i - j <= 0)
            {
                two_team = j;
                break;
            }
        if (two_team != -1)
        {
            int s = 0;
            for (int l = 0, r = max(0ll, min(K, 2 * two_team - 1)); l < r; l++, r--)
                s = max(s, group[l] + group[r]);
            for (int j = 2 * two_team; j < K; j++)
                s = max(s, group[j]);
            ans = min(ans, s * i);
        }
    }

    cout << ans << "\n";

    return 0;
}
