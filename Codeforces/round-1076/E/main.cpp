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
        vector<int> a;
        vector<int> dp(n + 1, 0);
        a.reserve(n);
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (dp[tmp] == 1)
                continue;
            a.push_back(tmp);
            dp[tmp] = 1;
        }

        sort(a.begin(), a.end());

        for (int i = 1; i < n + 1; ++i) {
            cout << (dp[i] == 0 ? -1 : dp[i]) << " \n"[i == n];
            if (dp[i] == 0)
                continue;
            for (auto& mul : a) {
                ll prod{ static_cast<ll>(i) * mul };
                if (prod > n)
                    break;
                if (dp[prod] == 0 || dp[i] + 1 < dp[prod]) {
                    dp[prod] = dp[i] + 1;
                }
            }
        }
    }
}
