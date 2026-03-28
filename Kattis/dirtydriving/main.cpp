#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p;
    cin >> n >> p;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    int dist{ 0 };
    for (int i = 0; i < n; ++i) {
        dist = max(dist, (p * (i + 1)) - v[i]);
    }
    cout << dist + v[0] << "\n";
}
