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
        bool t{ false };
        bool f{ false };

        while (n--) {
            int tmp;
            cin >> tmp;
            if (tmp == 67)
                t = true;
            if (tmp == 1)
                f = false;
        }
        if (t && f) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}
