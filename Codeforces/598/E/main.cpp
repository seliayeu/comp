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
    
    vector<vector<vector<int>>> dp(31, vector<vector<int>>(31, vector<int>(51, numeric_limits<int>::max())));
    for (int i = 1; i <= 30; ++i) {
        for (int j = i; j <= 30; ++j) {
            // if (j > i)
            //     continue;
            for (int k = 1; k <= 50; ++k) {
                if (dp[i][j][k] != numeric_limits<int>::max())
                    continue;

                if (i * j == k) {
                    dp[i][j][k] = 0;
                    break;
                }

                int cost{ numeric_limits<int>::max() };
                for (int ii = 1; ii < i; ++ii) {
                    int m1{ ii }, m2{ i - ii };

                    // either fits in m1 * j, m2 * j, or has split
                    if (k <= m1 * j) // if fits within smaller piece
                        cost = min(cost, j * j + dp[min(m1, j)][max(m1, j)][k]);
                    if (k <= m2 * j) // if fits within smaller piece
                        cost = min(cost, j * j + dp[min(m2, j)][max(m2, j)][k]);
                    if (k > m2 * j)
                        cost = min(cost, j * j + dp[min(m1, j)][max(m1, j)][k - m2 * j]);
                    if (k > m1 * j)
                        cost = min(cost, j * j + dp[min(m2, j)][max(m2, j)][k - m1 * j]);
                }
                for (int jj = 1; jj < j; ++jj) {
                    int n1{ jj }, n2{ j - jj };
                    // either fits in n1 * i, n2 * i, or has split
                    if (k <= n1 * i) // if fits within smaller piece
                        cost = min(cost, i * i + dp[min(n1, i)][max(n1, i)][k]);
                    if (k <= n2 * i) // if fits within smaller piece
                        cost = min(cost, i * i + dp[min(n2, i)][max(n2, i)][k]);
                    if (k > n2 * i)
                        cost = min(cost, i * i + dp[min(n1, i)][max(n1, i)][k - n2 * i]);
                    if (k > n1 * i)
                        cost = min(cost, i * i + dp[min(n2, i)][max(n2, i)][k - n1 * i]);
                }

                dp[i][j][k] = cost;
            }
        }
    }

    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;
        
        if (m > n)
            swap(m, n);

        cout << dp[m][n][p] << "\n";
    }
}
