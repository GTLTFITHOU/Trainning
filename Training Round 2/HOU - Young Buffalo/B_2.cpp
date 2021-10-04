#include <bits/stdc++.h>
using namespace std;
#define int long long
// author: Dat Trinh
int t ;
string ss ;
const int MOD = 10000;
const string tg = "welcome to code jam";
const int tgl= 19;

int dp(int i, int j, const string& ss, vector<vector<int>>& mem) 
{
    if (ss.length() - i < tgl- j)
        return 0;

    if (mem[i][j] == -1) {
        const string substr = ss.substr(i);
        if (j == 18)
            mem[i][j] = count(substr.begin(),substr.end(),tg.back());
        else
            mem[i][j] = ((ss[i] == tg[j] ? dp(i + 1, j + 1, ss, mem) : 0) + dp(i + 1, j, ss, mem)) % MOD;
    }
    return mem[i][j] ;
}

string solve( const string& ss)
{
    vector<vector<int>> mem(ss.length(), vector<int>(19, -1));
    string cnt = to_string(dp(0, 0, ss, mem));
    return string(4 - cnt.length(), '0') + cnt; 
}

void unstoppable()
{
    cin >> t;

    cin.ignore() ;

    for (int i = 1; i <= t; ++i)
    {
        getline(cin, ss);
        cout << "Case #" << i << ": " << solve(ss) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1 ;
    while(T--)
{
    unstoppable();
 }


}

