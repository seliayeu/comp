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
        int n, s, x;
        cin >> n >> s >> x;
        int sum{ 0 };
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            sum += tmp;
        }

        if (s == sum || (s > sum && (s - sum) % x == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        // cout << ((s - sum) % x == 0 ? "YES\n" : "NO\n");
    }
}
