#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // vector<int> dp(n + 1, 100001);
    int dp[100001];
    dp[1] = 1;

    for (int i = 2; i < n + 1; ++i) {
        dp[i] = i;
        for (int j = 1; j < i; ++j)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);

        int tmp = i, tmp2 = 0;
        int currPlace = 1;

        while (tmp > 0) {
            int oldTmp = tmp;
            tmp2 += currPlace * (tmp % 10);
            currPlace *= 10;
            tmp /= 10;
            if (tmp2 == 0 || (oldTmp % 10) == 0)
                continue;
            dp[i] = min(dp[i], dp[tmp] + dp[tmp2]);
        }

        for (int j = 2; j < i / 2; ++j)
            if ((i % j == 0))
                dp[i] = min(dp[i], dp[j] + dp[i / j]);
    }

    cout << dp[n];
}
