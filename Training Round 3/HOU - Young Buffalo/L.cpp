#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int t, a, b, c;
int tron(float a){
	if (a == int(a))
		return a;
	else return a + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> t;
	
	while (t--){
		cin >> a >> b >> c;
		int g1 = min(a,c), g2 = tron(max(a,c) / 2.0), g3 = max(a,c) / 2;
		while (b > 0){
			if (g1 <= g2 && g1 <= g3){
				g1++;
				b--;
			} else if (g2 <= g1 && g2 <= g3){
				g2++;
				b--;
			} else if (g3 <= g1 && g3 <= g2){
				g3++;
				b--;
			}
		}
		cout << max (g1, max(g2,g3)) << "\n";
	}


}

