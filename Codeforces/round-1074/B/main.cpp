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
        int res{0};
    int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            res = max(res, tmp);
        }
        cout << res * n << "\n";
    }
}

