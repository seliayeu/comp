#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto& x : a)
            cin >> x;

        int res{ 0 };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(a[i] ^ a[j], res);
            }
        }

        cout << res << "\n";
    }
}
