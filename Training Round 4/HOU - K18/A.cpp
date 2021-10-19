#include <bits/stdc++.h>
using namespace std;

int N;

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    vector<int> A(N);
    for (auto &e : A)
        cin >> e;
    auto mn = min_element(A.begin(), A.end()) - A.begin();
    auto mx = max_element(A.begin(), A.end()) - A.begin();
    swap(A[mn], A[mx]);
    for (auto e : A)
        cout << e << " ";

    return 0;
}