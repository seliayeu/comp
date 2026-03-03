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
        string s;
        cin >> s;

        int res{ 0 };
        char prev{ '?' };

        for (auto& c : s) {
            if (c == prev)
                continue;
            prev = c;
            res++;
        }

        if (s[0] == s[n - 1]) {
            cout << res << "\n";
        } else {
            cout << (res + (res < s.size() ? 1 : 0)) << "\n";
        }
    }
}
