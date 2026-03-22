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

    vector<vector<double>> dp(100000, vector<double>(100));
    while (t--) {
        int n;
        cin >> n;
        dp.resize(n);

        for (int i = 0; i < n; ++i) {
            int c, p;
            cin >> c >> p;

            for (int j = 0; j <= 100; ++j)
                dp[i][j] = -1;
            if (i == 0) {
                dp[i][100] = 0;
                dp[i][100 - p] = c;
                continue;
            }

            for (int j = 100; j >= 0; --j) {
                if (p > j)
                    break;
                if (dp[i - 1][j] == -1)
                    continue;
                dp[i][j] = 0;
            }
        }


    }
}
