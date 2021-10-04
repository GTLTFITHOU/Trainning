#include <bits/stdc++.h>
using namespace std;

#define show(x) cout << (#x) << " is " << (x) << endl
#define ll long long
#define len(s) (int)s.length()
#define epb emplace_back
#define fir first
#define sed second
#define sz(ds) (int)ds.size()
#define all(arr) arr.begin(), arr.end()

map< char , vector<int> > mp;
const string src = "welcome to code jam";

ll dp[300][30];

const int mod = 1e4;

int main() {
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	string st;
	getline(cin, st);
	int t = stoi(st);

	int test = 1;

	while (t--) {
		string s;
		getline(cin, s);
		// cout<<"'"<<s<<"'"<<endl;
		ll ans = 0;

		for (int i = 0 ; i < 300 ; i++) {
			for (int j = 0 ; j < 30 ; j++) {
				dp[i][j] = 0;
			}
		}


		int n = len(s);

		for (int i = 0 ; i < n ; i++) {

			//dp[ s[i] - 'a' + 1 ] ++;

			if (s[i] == 'w') {
				dp['w'][0] = ( dp['w'][0] + 1 ) % mod;
				continue;
			}

			if (s[i] == 'e') {
				// 1-w, 2-m, 3-d

				dp['e'][1] = ( dp['e'][1] + dp['w'][0] ) % mod;

				dp['e'][6] = ( dp['e'][6]  + dp['m'][5] ) % mod;

				dp['e'][14] = ( dp['e'][14] + dp['d'][13] ) % mod;
				continue;
			}
			if (s[i] == 'o') {

				dp['o'][4] = (dp['o'][4] + dp['c'][3]) % mod;

				dp['o'][9] = (dp['o'][9] + dp['t'][8]) % mod;

				dp['o'][12] = (dp['o'][12] + dp['c'][11]) % mod;
				continue;
			}

			if (s[i] == 'm') {
				// 1-w, 2-m, 3-d

				dp['m'][5] = (dp['m'][5]  + dp['o'][4]) % mod;

				dp['m'][18] = (dp['m'][18] + dp['a'][17]) % mod;



				continue;
			}
			if (s[i] == ' ') {
				// 1-w, 2-m, 3-d

				dp[' '][7] = ( dp[' '][7]  + dp['e'][6]) % mod;

				dp[' '][10] = ( dp['o'][9] + dp[' '][10] ) % mod;

				dp[' '][15] = (dp['e'][14] + dp[' '][15]) % mod;

				continue;
			}
			if (s[i] == 'c') {
				dp['c'][3] = (dp['c'][3] + dp['l'][2]) % mod;

				dp['c'][11] = (dp['c'][11] + dp[' '][10]) % mod;

				continue;
			}

			if (s[i] == 't') {
				dp['t'][8] = (dp['t'][8] + dp[' '][7]) % mod;
			}
			if (s[i] == 'l') {
				dp['l'][2] = (dp['l'][2] + dp['e'][1]) % mod;
			}
			if (s[i] == 'a') {
				dp['a'][17] = (dp['a'][17] + dp['j'][16]) % mod;
			}
			if (s[i] == 'j') {
				dp['j'][16] = (dp['j'][16] + dp[' '][15]) % mod;
			}
			if (s[i] == 'd') {
				dp['d'][13] = (dp['d'][13] + dp['o'][12]) % mod;
			}

		}
		string sans = to_string(dp['m'][18]);
		while (len(sans) < 4) {
			sans = "0" + sans;
		}
		cout << "Case #" << test << ": " << sans << endl;
		test ++;
	}
}