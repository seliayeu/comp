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
        ll x, y;
        cin >> x >> y;

        if (y > 0) {
            x -= 2 * y;
        } else if (y < 0) {
            x -= -4 * y;
        }

        if (x >= 0 && x % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
